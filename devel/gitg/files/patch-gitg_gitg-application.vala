From 7be88eabc65c158e0c9570c548762357209e129f Mon Sep 17 00:00:00 2001
From: Alberto Fanjul <albertofanjul@gmail.com>
Date: Thu, 29 Nov 2018 22:01:07 +0100
Subject: [PATCH] vala: Avoid using struct as namespace

---
 gitg/gitg-application.vala | 102 +++++++++++++++++--------------------
 1 file changed, 48 insertions(+), 54 deletions(-)

diff --git a/gitg/gitg-application.vala b/gitg/gitg-application.vala
index e6f935fb..08889370 100644

--- gitg/gitg-application.vala.orig	2018-10-25 22:09:17.000000000 +0200
+++ gitg/gitg-application.vala	2019-02-26 20:27:25.173745000 +0100
@@ -22,8 +22,37 @@
 
 public class Application : Gtk.Application
 {
+	// Do this to pull in config.h before glib.h (for gettext...)
+	private const string version = Gitg.Config.VERSION;
+
 	private Settings d_state_settings;
 
+	public static bool app_quit = false;
+	public static string activity;
+	public static bool no_wd = false;
+	public static bool standalone = false;
+	public static ApplicationCommandLine app_command_line;
+
+	public const OptionEntry[] entries = {
+		{"version", 'v', OptionFlags.NO_ARG, OptionArg.CALLBACK,
+		 (void *)show_version_and_quit, N_("Show the application’s version"), null},
+		{"activity", '\0', 0, OptionArg.STRING,
+		 ref activity, N_("Start gitg with a particular activity"), null},
+		{"commit", 'c', OptionFlags.NO_ARG, OptionArg.CALLBACK,
+		 (void *)commit_activity, N_("Start gitg with the commit activity (shorthand for --activity commit)"), null},
+		{"no-wd", 0, 0, OptionArg.NONE,
+		 ref no_wd, N_("Do not try to load a repository from the current working directory"), null},
+		{"standalone", 0, 0, OptionArg.NONE,
+		 ref standalone, N_("Run gitg in standalone mode"), null},
+		{null}
+	};
+
+	private static bool commit_activity()
+	{
+		activity = "commit";
+		return true;
+	}
+
 	public Settings state_settings
 	{
 		owned get { return d_state_settings; }
@@ -37,41 +66,6 @@
 		              ApplicationFlags.SEND_ENVIRONMENT);
 	}
 
-	private struct Options
-	{
-		public static bool quit = false;
-		public static string activity;
-		public static bool no_wd = false;
-		public static bool standalone = false;
-
-		public static ApplicationCommandLine command_line;
-
-		private static bool commit_activity()
-		{
-			activity = "commit";
-			return true;
-		}
-
-		public const OptionEntry[] entries = {
-			{"version", 'v', OptionFlags.NO_ARG, OptionArg.CALLBACK,
-			 (void *)show_version_and_quit, N_("Show the application's version"), null},
-
-			{"activity", '\0', 0, OptionArg.STRING,
-			 ref activity, N_("Start gitg with a particular activity"), null},
-
-			{"commit", 'c', OptionFlags.NO_ARG, OptionArg.CALLBACK,
-			 (void *)commit_activity, N_("Start gitg with the commit activity (shorthand for --activity commit)"), null},
-
-			{"no-wd", 0, 0, OptionArg.NONE,
-			 ref no_wd, N_("Do not try to load a repository from the current working directory"), null},
-
-			{"standalone", 0, 0, OptionArg.NONE,
-			 ref standalone, N_("Run gitg in standalone mode"), null},
-
-			{null}
-		};
-	}
-
 	private PreferencesDialog d_preferences;
 
 #if GTK_SHORTCUTS_WINDOW
@@ -80,7 +74,7 @@
 
 	static construct
 	{
-		Options.activity = "";
+		activity = "";
 	}
 
 	private static bool show_version_and_quit()
@@ -89,7 +83,7 @@
 		              Environment.get_application_name(),
 		              Config.VERSION);
 
-		Options.quit = true;
+		app_quit = true;
 		return true;
 	}
 
@@ -97,7 +91,7 @@
 	{
 		var ctx = new OptionContext(_("- Git repository viewer"));
 
-		ctx.add_main_entries(Options.entries, Config.GETTEXT_PACKAGE);
+		ctx.add_main_entries(entries, Config.GETTEXT_PACKAGE);
 		ctx.add_group(Gtk.get_option_group(true));
 
 		var cmdexts = new GitgExt.CommandLine[0];
@@ -152,12 +146,12 @@
 			return true;
 		}
 
-		if (Options.standalone)
+		if (standalone)
 		{
 			set_flags(get_flags() | ApplicationFlags.NON_UNIQUE);
 		}
 
-		if (Options.quit)
+		if (app_quit)
 		{
 			exit_status = 0;
 			return true;
@@ -182,18 +176,18 @@
 			return 1;
 		}
 
-		if (Options.quit)
+		if (app_quit)
 		{
 			return 0;
 		}
 
 		if (!cmd.get_is_remote())
 		{
-			Options.command_line = cmd;
+			app_command_line = cmd;
 		}
 
-		var tmpcmd = Options.command_line;
-		Options.command_line = cmd;
+		var tmpcmd = app_command_line;
+		app_command_line = cmd;
 
 		if (argv.length > 1)
 		{
@@ -205,14 +199,14 @@
 				files += File.new_for_commandline_arg(arg);
 			}
 
-			open_command_line(files, Options.activity, command_lines);
+			open_command_line(files, activity, command_lines);
 		}
 		else
 		{
 			activate_command_line(command_lines);
 		}
 
-		Options.command_line = tmpcmd;
+		app_command_line = tmpcmd;
 		return 1;
 	}
 
@@ -455,17 +449,17 @@
 
 	private void activate_command_line(GitgExt.CommandLines command_lines)
 	{
-		if (Options.no_wd)
+		if (no_wd)
 		{
-			present_window(Options.activity, command_lines);
+			present_window(activity, command_lines);
 		}
 		else
 		{
 			// Otherwise open repository from current dir
-			string? wd = Options.command_line.get_cwd();
+			string? wd = app_command_line.get_cwd();
 
-			open(new File[] { File.new_for_path(wd) }, Options.activity);
-			present_window(Options.activity, command_lines);
+			open(new File[] { File.new_for_path(wd) }, activity);
+			present_window(activity, command_lines);
 		}
 	}
 
@@ -526,7 +520,7 @@
 			if (window != null)
 			{
 				// Present the window with this repository open
-				window.set_environment(Options.command_line.get_environ());
+				window.set_environment(app_command_line.get_environ());
 				window.present(hint, command_lines);
 				continue;
 			}
@@ -551,7 +545,7 @@
 
 		if (window != null)
 		{
-			window.set_environment(Options.command_line.get_environ());
+			window.set_environment(app_command_line.get_environ());
 		}
 
 		present_window(hint, command_lines);
@@ -573,7 +567,7 @@
 
 		var w = (Gitg.Window)windows.first().data;
 
-		w.set_environment(Options.command_line.get_environ());
+		w.set_environment(app_command_line.get_environ());
 		w.present(activity, command_lines);
 	}
 }
