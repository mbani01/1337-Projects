mysql_install_db --user=mysql --datadir=/var/lib/mysql
rc-status
rc-service mariadb start
mysql --user=root -e "CREATE DATABASE wpdb; use wpdb"
mysql -u root -e "CREATE USER 'admin'@'%' IDENTIFIED BY '1234'"
mysql -u root -e "GRANT ALL PRIVILEGES ON *.* TO 'admin'@'%'; FLUSH PRIVILEGES;"
mysql -u root wpdb < /wpdb1.sql 
rc-update add mariadb default