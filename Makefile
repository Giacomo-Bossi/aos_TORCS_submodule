docker_build:
	docker build -t aos_proj .

docker_run:
	docker run -e DISPLAY=$(shell echo $$DISPLAY) -it -v $(shell pwd)/pilot:/usr/local/src/torcs-1.3.7/src/drivers aos_proj /bin/bash	

