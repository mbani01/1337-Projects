# if [ -z "$(ls -A /var/lib/new)" ]; then
#    cp /var/lib/mysql/* /var/lib/new
# fi
# ln -s /var/lib/mysql /var/lib/new
mkdir /run/openrc
touch /run/openrc/softlevel
rc-status
rc-service mariadb stop
rc-service mariadb start
sed  -i "s/iipa/$ip/g" /wpdb1.sql 
mysql --user=root -e "CREATE DATABASE wpdb; use wpdb"
mysql -u root -e "CREATE USER 'admin'@'%' IDENTIFIED BY '1234'"
mysql -u root -e "GRANT ALL PRIVILEGES ON *.* TO 'admin'@'%'; FLUSH PRIVILEGES;"
mysql -u root wpdb < /wpdb1.sql 
rc-update add mariadb default
tail -f /dev/null

# kubectl cp mysql $(kubectl get pods | grep "mysql-*" | awk '{print $1}'):/var/lib/mysql