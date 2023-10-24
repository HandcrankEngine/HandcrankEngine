# Building with Docker

```bash
docker build --network=host --tag handcrank .
docker create --name extract handcrank
docker cp extract:/usr/src/app/build ./
docker rm extract
```
