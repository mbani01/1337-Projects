mkdir /run/openrc
touch /run/openrc/softlevel
rc-status
rc-service mariadb stop
rc-service mariadb start
sed  -i "s/iipa/$ip/g" /wpdb1.sql 
mysql --user=root -e "CREATE DATABASE wpdb; use wpdb"
mysql -u root -e "CREATE USER 'admin'@'%' IDENTIFIED BY '1234'"
mysql -u root -e "GRANT ALL ON *.* TO 'admin'@'%'; FLUSH PRIVILEGES;"
mysql -u root wpdb < /wpdb1.sql 
rc-update add mariadb default
tail -f /dev/null