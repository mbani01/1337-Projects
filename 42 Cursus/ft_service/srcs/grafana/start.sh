chown -R grafana:grafana /grafana
exec su-exec grafana /usr/bin/grafana-server --homepath=/grafana