#!bin/bash
apt-get -qq install apt-utils 
apt-get -qq install unzip 
apt-get -qq install nginx
apt-get -qq install wget
wget https://dev.mysql.com/get/mysql-apt-config_0.8.13-1_all.deb
apt-get -qq install lsb-release
apt-get -qq install gnupg
apt-get -qq install php7.3-fpm
apt-get -qq install php-mysql
echo "mysql-apt-config mysql-apt-config/select-server select mysql-5.7" | /usr/bin/debconf-set-selections
DEBIAN_FRONTEND=noninteractive dpkg --install mysql-apt-config_0.8.13-1_all.deb
DEBIAN_FRONTEND=noninteractive apt-get -qq update
DEBIAN_FRONTEND=noninteractive apt-get -qq install mysql-server
wget https://files.phpmyadmin.net/phpMyAdmin/4.9.2/phpMyAdmin-4.9.2-all-languages.zip
unzip phpMyAdmin-4.9.2-all-languages.zip
mv phpMyAdmin-4.9.2-all-languages /var/www/html/phpmyadmin
wget http://fr.wordpress.org/latest-fr_FR.tar.gz
tar -xzvf latest-fr_FR.tar.gz 
mv wordpress/* /var/www/html
rm -rf wordpress phpMyAdmin-4.9.2-all-languages.zip mysql-apt-config_0.8.13-1_all.deb
rm /etc/nginx/sites-available/default