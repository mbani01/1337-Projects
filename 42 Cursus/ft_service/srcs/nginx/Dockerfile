FROM alpine
RUN apk update
RUN apk add nginx openssh openrc
RUN mkdir /run/openrc && \
touch /run/openrc/softlevel && \
rc-status && \
rc-update add sshd
RUN mkdir /run/nginx/
COPY default.conf /etc/nginx/conf.d/default.conf
COPY nginx.crt /etc/ssl/certs/nginx.crt
COPY nginx.key /etc/ssl/private/nginx.key
RUN echo "<h1>Hello world!</h1>" > /var/www/localhost/htdocs/index.html
RUN echo "daemon off;" >> /etc/nginx/nginx.conf
COPY ssh_config etc/ssh/
COPY start.sh /
ENTRYPOINT [ "sh", "start.sh" ]
# CMD nginx
EXPOSE 80 443 22