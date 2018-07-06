--- src/drivers/fluid_adriver.c.orig	2018-05-06 07:05:11 UTC
+++ src/drivers/fluid_adriver.c
@@ -64,6 +64,15 @@ int delete_fluid_oss_audio_driver(fluid_
 void fluid_oss_audio_driver_settings(fluid_settings_t* settings);
 #endif
 
+#if SNDIO_SUPPORT
+fluid_audio_driver_t* new_fluid_sndio_audio_driver(fluid_settings_t* settings,
+						   fluid_synth_t* synth);
+fluid_audio_driver_t* new_fluid_sndio_audio_driver2(fluid_settings_t* settings,
+						    fluid_audio_func_t func, void* data);
+int delete_fluid_sndio_audio_driver(fluid_audio_driver_t* p);
+void fluid_sndio_audio_driver_settings(fluid_settings_t* settings);
+#endif
+
 #if COREAUDIO_SUPPORT
 fluid_audio_driver_t* new_fluid_core_audio_driver(fluid_settings_t* settings,
 						  fluid_synth_t* synth);
@@ -122,6 +131,14 @@ int delete_fluid_file_audio_driver(fluid
 /* Available audio drivers, listed in order of preference */
 static const fluid_audriver_definition_t fluid_audio_drivers[] =
 {
+#if SNDIO_SUPPORT
+    { "sndio",
+        new_fluid_sndio_audio_driver,
+        new_fluid_sndio_audio_driver2,
+        delete_fluid_sndio_audio_driver,
+        fluid_sndio_audio_driver_settings },
+#endif
+
 #if JACK_SUPPORT
     { "jack",
         new_fluid_jack_audio_driver,
@@ -238,7 +255,9 @@ void fluid_audio_driver_settings(fluid_s
                                FLUID_DEFAULT_AUDIO_RT_PRIO, 0, 99, 0, NULL, NULL);
 
   /* Set the default driver */
-#if JACK_SUPPORT
+#if SNDIO_SUPPORT
+  fluid_settings_register_str(settings, "audio.driver", "sndio", 0, NULL, NULL);
+#elif JACK_SUPPORT
   fluid_settings_register_str(settings, "audio.driver", "jack", 0, NULL, NULL);
 #elif ALSA_SUPPORT
   fluid_settings_register_str(settings, "audio.driver", "alsa", 0, NULL, NULL);
@@ -272,6 +291,9 @@ void fluid_audio_driver_settings(fluid_s
 #if OSS_SUPPORT
   fluid_settings_add_option(settings, "audio.driver", "oss");
 #endif
+#if SNDIO_SUPPORT
+  fluid_settings_add_option(settings, "audio.driver", "sndio");
+#endif
 #if COREAUDIO_SUPPORT
   fluid_settings_add_option(settings, "audio.driver", "coreaudio");
 #endif
