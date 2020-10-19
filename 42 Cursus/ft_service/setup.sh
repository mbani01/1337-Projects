minikube delete
minikube start --extra-config=apiserver.service-node-port-range=1-65535
eval $(minikube docker-env)
minikube ssh 'sudo mkdir /mnt/data; sudo mkdir /mnt/data/ftp; sudo chmod 777 /mnt/data/ '
minikube ssh 'sudo mkdir /mnt/data/influxdb; sudo mkdir /mnt/data/mysql; sudo chmod 777 /mnt/data/ '
kubectl apply -f srcs/ftps/ftp_pv.yaml
kubectl apply -f srcs/ftps/ftp_pvc.yaml
kubectl apply -f srcs/mysql/mysql-pv.yml
kubectl apply -f srcs/mysql/mysql-pvc.yml
docker build -t my-influxdb srcs/influxdb
kubectl create -f srcs/influxdb/influxdb.yaml
docker build -t my-ftp --build-arg ip=$(minikube ip) srcs/ftps
kubectl cp srcs/mysql/mysql $(kubectl get pods | grep "mysql-*" | awk '{print $1}'):/var/lib/
docker build -t my-nginx srcs/nginx
docker build -t my-wdp srcs/wordpress
docker build -t mysql --build-arg ip=$(minikube ip) srcs/mysql
docker build -t my-php srcs/phpmyadmin
docker build -t my-grafana srcs/grafana
kubectl create -f srcs/nginx/nginx.yaml
kubectl create -f srcs/grafana/grafana.yaml
kubectl create -f srcs/mysql/mysql.yaml
kubectl create -f srcs/nginx/ingress.yaml
kubectl create -f srcs/wordpress/wordpress.yaml
kubectl create -f srcs/phpmyadmin/php.yaml
minikube addons enable ingress
sleep 20
kubectl cp srcs/mysql/sc.sh $(kubectl get pods | grep "mysql*" | grep -v pause| awk '{print $1}'):/var/lib/
kubectl exec -i $(kubectl get pods | grep "mysql*" | grep -v pause| awk '{print $1}') -- sh /var/lib/sc.sh
kubectl exec -i $(kubectl get pods | grep "influxdb" | grep -v pause| awk '{print $1}') -- sh /create.sh
# kubectl exec -i $(kubectl get pods | grep "influxdb" | grep -v pause| awk '{print $1}') -- sh /create1.sh