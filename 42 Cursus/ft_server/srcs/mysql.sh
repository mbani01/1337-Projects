#!bin/bash
chown -R mysql: /var/lib/mysql
service mysql start
#mysql -u root -e "CREATE DATABASE wpdb; use wpdb; source localhost.sql;"
mysql -u root -e "CREATE USER 'admin'@'localhost' IDENTIFIED BY '1234'"
mysql --user=root -e "CREATE DATABASE wpdb; use wpdb; source localhost.sql;"
mysql -u root -e "GRANT ALL ON *.* TO 'admin'@'localhost'; FLUSH PRIVILEGES;"
