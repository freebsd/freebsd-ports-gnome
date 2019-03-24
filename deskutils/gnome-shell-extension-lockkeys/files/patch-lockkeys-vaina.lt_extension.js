https://github.com/kazysmaster/gnome-shell-extension-lockkeys/pull/56

From 29a13b5788434c889121d742f67eed3d42bf29ab Mon Sep 17 00:00:00 2001
From: =?UTF-8?q?Rapha=C3=ABl=20Rochet?= <raphael@rri.fr>
Date: Sat, 16 Mar 2019 11:40:03 +0100
Subject: [PATCH] Quick and dirty fix to make it work with gnome 3.32

---
 lockkeys@vaina.lt/extension.js | 42 ++++++++++++++++++----------------
 1 file changed, 22 insertions(+), 20 deletions(-)

diff --git a/lockkeys@vaina.lt/extension.js b/lockkeys@vaina.lt/extension.js
index 6d98041..56e2e74 100644
--- lockkeys@vaina.lt/extension.js
+++ lockkeys@vaina.lt/extension.js
@@ -50,31 +50,33 @@ function disable() {
 	indicator.destroy();
 }
 
-function LockKeysIndicator() {
-	this._init();
-}
+const LockKeysIndicator = new Lang.Class({
+	Name: 'LockKeysIndicator',
+	Extends: PanelMenu.Button,
 
-LockKeysIndicator.prototype = {
-	__proto__: PanelMenu.Button.prototype,
+	_getCustIcon: function(icon_name) {
+		let gicon = Gio.icon_new_for_string( Meta.dir.get_child('icons').get_path() + "/" + icon_name + ".svg" );
+		return gicon;
+	},
 
 	_init: function() {
-		PanelMenu.Button.prototype._init.call(this, St.Align.START);
+		this.parent(0.0, "LockKeysIndicator");
 
 		// For highlight to work properly you have to use themed
 		// icons. Fortunately we can add our directory to the search path.
 		Gtk.IconTheme.get_default().append_search_path(Meta.dir.get_child('icons').get_path());
 
-		this.numIcon = new St.Icon({icon_name: "numlock-enabled-symbolic",
+		this.numIcon = new St.Icon({gicon: this._getCustIcon("numlock-enabled-symbolic"),
 			style_class: 'system-status-icon'});
-		this.capsIcon = new St.Icon({icon_name: "capslock-enabled-symbolic",
+		this.capsIcon = new St.Icon({gicon: this._getCustIcon("capslock-enabled-symbolic"),
 			style_class: 'system-status-icon'});
 
-		this.layoutManager = new St.BoxLayout({vertical: false,
+		let layoutManager = new St.BoxLayout({vertical: false,
 			style_class: 'lockkeys-container'});
-		this.layoutManager.add(this.numIcon);
-		this.layoutManager.add(this.capsIcon);
+		layoutManager.add_child(this.numIcon);
+		layoutManager.add_child(this.capsIcon);
 
-		this.actor.add_actor(this.layoutManager);
+		this.actor.add_child(layoutManager);
 
 		this.numMenuItem = new PopupMenu.PopupSwitchMenuItem(_("Num Lock"), false, { reactive: false });
 		this.menu.addMenuItem(this.numMenuItem);
@@ -182,7 +184,7 @@ LockKeysIndicator.prototype = {
 	_getCapslockState: function() {
 		return Keymap.get_caps_lock_state();
 	}
-}
+});
 
 function HighlightIndicator(panelButton) {
 	this._init(panelButton);
@@ -210,14 +212,14 @@ HighlightIndicator.prototype = {
 		this.panelButton.actor.visible = true;
 		
 		if (numlock_state)
-			this.numIcon.set_icon_name('numlock-enabled-symbolic');
+			this.numIcon.set_gicon( this.panelButton._getCustIcon('numlock-enabled-symbolic') );
 		else
-			this.numIcon.set_icon_name('numlock-disabled-symbolic');
+			this.numIcon.set_gicon( this.panelButton._getCustIcon('numlock-disabled-symbolic') );
 
 		if (capslock_state)
-			this.capsIcon.set_icon_name('capslock-enabled-symbolic');
+			this.capsIcon.set_gicon( this.panelButton._getCustIcon('capslock-enabled-symbolic') );
 		else
-			this.capsIcon.set_icon_name('capslock-disabled-symbolic');
+			this.capsIcon.set_gicon( this.panelButton._getCustIcon('capslock-disabled-symbolic') );
 
 	}
 }
@@ -233,8 +235,8 @@ ShowhideIndicator.prototype = {
 		this.numIcon = panelButton.numIcon; 
 		this.capsIcon = panelButton.capsIcon;
 		
-		this.numIcon.set_icon_name('numlock-enabled-symbolic');
-		this.capsIcon.set_icon_name('capslock-enabled-symbolic');
+		this.numIcon.set_gicon( this.panelButton._getCustIcon('numlock-enabled-symbolic') );
+		this.capsIcon.set_gicon( this.panelButton._getCustIcon('capslock-enabled-symbolic') );
 	},
 	
 	displayState: function(numlock_state, capslock_state) {
@@ -279,4 +281,4 @@ Configuration.prototype = {
 		let widget_style = this.settings.get_string(STYLE);
 		return widget_style == STYLE_SHOWHIDE;
 	}
-}
\ No newline at end of file
+}
