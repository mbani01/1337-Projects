FROM alpine
ARG ip
ENV ip=$ip
RUN echo http://dl-cdn.alpinelinux.org/alpine/edge/testing >> /etc/apk/repositories \
&& apk update \
&& apk add pure-ftpd \
&& adduser -D mbani \
&& echo mbani:mbani | chpasswd \
&& mkdir -p ftps/mbani 
COPY pure-ftpd.pem /etc/ssl/private/
RUN chmod 600 /etc/ssl/private/pure-ftpd.pem
COPY    setup.sh /
EXPOSE 21 21000
ENTRYPOINT [ "sh", "setup.sh" ]