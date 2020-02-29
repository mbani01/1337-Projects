minikube delete
minikube start --extra-config=apiserver.service-node-port-range=1-65535
eval $(minikube docker-env)
minikube ssh 'sudo mkdir /mnt/data; sudo mkdir /mnt/data/ftp; sudo chmod 777 /mnt/data/ '
# minikube ssh 'sudo mkdir /mnt/data/mysql; sudo chmod 777 /mnt/data/ '
kubectl apply -f srcs/ftps/ftp_pv.yaml
kubectl apply -f srcs/ftps/ftp_pvc.yaml
# kubectl apply -f srcs/mysql/mysql-pv.yml
kubectl apply -f srcs/mysql/mysql-pvc.yml
docker build -t my-ftp --build-arg ip=$(minikube ip) srcs/ftps
docker build -t my-nginx srcs/nginx
docker build -t my-wdp srcs/wordpress
docker build -t mysql --build-arg ip=$(minikube ip) srcs/mysql
docker build -t my-php srcs/phpmyadmin
kubectl create -f srcs/nginx/nginx.yaml
kubectl create -f srcs/mysql/mysql.yaml
kubectl create -f srcs/nginx/ingress.yaml
kubectl create -f srcs/wordpress/wordpress.yaml
kubectl create -f srcs/phpmyadmin/php.yaml
# kubectl apply -f https://raw.githubusercontent.com/kubernetes/ingress-nginx/master/deploy/static/mandatory.yaml  
minikube addons enable ingress