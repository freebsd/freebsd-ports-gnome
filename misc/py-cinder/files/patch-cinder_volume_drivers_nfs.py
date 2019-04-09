--- cinder/volume/drivers/nfs.py.orig	2018-06-18 13:37:33 UTC
+++ cinder/volume/drivers/nfs.py
@@ -182,10 +182,10 @@ class NfsDriver(remotefs.RemoteFSSnapDriverDistributed
 
         self.shares = {}  # address : options
 
-        # Check if mount.nfs is installed on this system; note that we
+        # Check if mount_nfs is installed on this system; note that we
         # need to be root, to also find mount.nfs on distributions, where
         # it is not located in an unprivileged users PATH (e.g. /sbin).
-        package = 'mount.nfs'
+        package = 'mount_nfs'
         try:
             self._execute(package, check_exit_code=False,
                           run_as_root=True)
@@ -342,16 +342,16 @@ class NfsDriver(remotefs.RemoteFSSnapDriverDistributed
         """
         mount_point = self._get_mount_point_for_share(nfs_share)
 
-        df, _ = self._execute('stat', '-f', '-c', '%S %b %a', mount_point,
+        df, _ = self._execute('df', '-k', mount_point,
                               run_as_root=self._execute_as_root)
-        block_size, blocks_total, blocks_avail = map(float, df.split())
-        total_available = block_size * blocks_avail
-        total_size = block_size * blocks_total
+        df = df.splitlines()[1]
+        block_size = 1024
+        total_available = block_size * int(df.split()[3])
+        total_size = block_size * int(df.split()[1])
 
-        du, _ = self._execute('du', '-sb', '--apparent-size', '--exclude',
-                              '*snapshot*', mount_point,
+        du, _ = self._execute('du', '-Aks', mount_point,
                               run_as_root=self._execute_as_root)
-        total_allocated = float(du.split()[0])
+        total_allocated = float(du.split()[0]) * 1024
         return total_size, total_available, total_allocated
 
     def _get_mount_point_base(self):
