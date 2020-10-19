adduser mbani -D
echo mbani:mbani | chpasswd
/etc/init.d/sshd start
nginx