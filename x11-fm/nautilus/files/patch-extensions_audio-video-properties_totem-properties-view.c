--- extensions/audio-video-properties/totem-properties-view.c.orig	2019-03-14 16:37:33 UTC
+++ extensions/audio-video-properties/totem-properties-view.c
@@ -224,7 +224,7 @@ update_audio (TotemPropertiesView    *props,
 
 	channels = gst_discoverer_audio_info_get_channels (info);
 	if (channels) {
-		char *string;
+		char *string = NULL;
 
 		if (channels > 2) {
 			string = g_strdup_printf ("%s %d.1", _("Surround"), channels - 1);
