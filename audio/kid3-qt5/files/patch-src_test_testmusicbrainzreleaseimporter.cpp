Fix test to reflect the current data in the MusicBrainz database.

--- src/test/testmusicbrainzreleaseimporter.cpp.orig	2018-12-21 05:40:14 UTC
+++ src/test/testmusicbrainzreleaseimporter.cpp
@@ -38,7 +38,7 @@ void TestMusicBrainzReleaseImporter::testQueryAlbums()
 {
   queryAlbums(QLatin1String("Wizard"), QLatin1String("Odin"));
   QStandardItemModel* albumModel = m_importer->getAlbumListModel();
-  QCOMPARE(albumModel->rowCount(), 3);
+  QCOMPARE(albumModel->rowCount(), 4);
   auto  item = static_cast<AlbumListItem*>(albumModel->item(0, 0));
   QVERIFY(item);
   QVERIFY(item->type() == AlbumListItem::Type);
@@ -54,9 +54,9 @@ void TestMusicBrainzReleaseImporter::testQueryTracks()
   QStringList titles;
   titles << QLatin1String("The Prophecy") << QLatin1String("Betrayer")
          << QLatin1String("Dead Hope") << QLatin1String("Dark God")
-         << QLatin1String("Loki's Punishment")
+         << QString::fromUtf8("Loki\u2019s Punishment")
          << QLatin1String("Beginning of the End")
-         << QLatin1String("Thor's Hammer")
+         << QString::fromUtf8("Thor\u2019s Hammer")
          << QLatin1String("Hall of Odin") << QLatin1String("The Powergod")
          << QLatin1String("March of the Einheriers")
          << QLatin1String("End of All");
@@ -66,7 +66,7 @@ void TestMusicBrainzReleaseImporter::testQueryTracks()
           << QLatin1String("5:08") << QLatin1String("4:01")
           << QLatin1String("5:01") << QLatin1String("5:06")
           << QLatin1String("5:21") << QLatin1String("5:40")
-          << QLatin1String("3:53");
+          << QLatin1String("3:55");
   QCOMPARE(m_trackDataModel->rowCount(), 11);
   for (int row = 0; row < 11; ++row) {
     QCOMPARE(m_trackDataModel->index(row, 0).data().toString(),
