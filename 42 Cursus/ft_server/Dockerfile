FROM debian:buster

RUN apt-get -y -qq update
COPY srcs/mysql.sh srcs/install.sh /
RUN  sh install.sh
COPY  srcs/localhost.sql /
RUN sh mysql.sh
RUN echo "daemon off;" >> /etc/nginx/nginx.conf
COPY srcs/default /etc/nginx/sites-available/default
COPY srcs/start.sh /
COPY srcs/wp-config.php /var/www/html
COPY srcs/nginx.crt srcs/nginx.key /etc/nginx/ssl/
EXPOSE 80 443
CMD sh start.sh