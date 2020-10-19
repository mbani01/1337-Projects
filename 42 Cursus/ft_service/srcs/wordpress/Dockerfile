FROM alpine
WORKDIR /usr/share/webapps/
RUN wget http://wordpress.org/latest.tar.gz \
 && tar -xzvf latest.tar.gz \
 && rm latest.tar.gz
RUN apk add php7-common php7-iconv php7-json php7-gd php7-curl \
 && apk add php7-xml php7-mysqli php7-imap php7-cgi fcgi php7-pdo php7-pdo_mysql \
 && apk add php7-soap php7-xmlrpc php7-posix php7-mcrypt php7-gettext php7-ldap \
 && apk add php7-ctype php7-dom \
 && apk add php php-fpm
COPY wp-config.php /usr/share/webapps/wordpress/
EXPOSE 5050
ENTRYPOINT php -S 0.0.0.0:5050 -t /usr/share/webapps/wordpress

# FROM alpine
# RUN apk update \
# && apk add php-fpm php git
# RUN /usr/sbin/php-fpm7;
# RUN git clone https://github.com/WordPress/WordPress \
# && mkdir -p WordPress/config && mkdir wp
# EXPOSE 5050


# if [ ! -f "/wp/index.php" ];then
#     mv WordPress/* /wp
# fi

# VOLUME [ "/wp" ]

# ENTRYPOINT php -S 0.0.0.0:5050 -t wp