FROM alpine
ENV INFLUXDB_VERSION 1.7.7
ENV TELEGRAF_VERSION 1.13.4
RUN apk add su-exec \
&& apk add wget influxdb
RUN wget https://dl.influxdata.com/influxdb/releases/influxdb-${INFLUXDB_VERSION}-static_linux_amd64.tar.gz
# RUN addgroup influxdb && \
#         adduser -s /bin/false -G influxdb -S -D influxdb
RUN tar -xzf influxdb-${INFLUXDB_VERSION}-static_linux_amd64.tar.gz && \
 chmod +x influxdb-*/* && \
 mkdir -p /var/lib/influxdb && \
 cp -a influxdb-*/* /usr/bin/ && \
 rm -rf *.tar.gz* influxdb-*/
RUN wget https://dl.influxdata.com/telegraf/releases/telegraf-${TELEGRAF_VERSION}-static_linux_amd64.tar.gz
 RUN tar -xzf telegraf-${TELEGRAF_VERSION}-static_linux_amd64.tar.gz && \
        chmod +x telegraf/* && \
        cp telegraf/telegraf /usr/bin/ && \
        rm -rf *.tar.gz* telegraf/ && \
        mkdir -p etc/telegraf
COPY telegraf.conf /etc/telegraf/
COPY start.sh /
COPY create.sh /
COPY create1.sh /
VOLUME [ "/var/run/docker.sock" ]
EXPOSE 8086
ENTRYPOINT [ "sh", "/start.sh" ]