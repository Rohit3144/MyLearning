docker build . -t webapp-color
docker run -d -p 8282:8080 webapp-color
http://<ip-address>:8282/
