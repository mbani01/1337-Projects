FROM alpine
ENV DB_DATA_PATH="/var/lib/mysql"
ENV DB_ROOT_PASS="mariadb_root_password"
ENV DB_USER="mariadb_user"
ENV DB_PASS="mariadb_user_password"
ENV MAX_ALLOWED_PACKET="200M"
ARG ip
ENV ip=$ip
RUN apk update \
&& apk add mariadb mariadb-client openrc \
&& mysql_install_db --user=mysql --datadir=${DB_DATA_PATH}

COPY mariadb-server.cnf /etc/my.cnf.d/
COPY mysql.sh /
COPY wpdb1.sql /
EXPOSE 3306
# RUN mkdir /var/lib/new
VOLUME [ "/var/lib/mysql" ]
ENTRYPOINT sh mysql.sh


