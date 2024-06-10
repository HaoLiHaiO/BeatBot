FROM gcc:latest

RUN apt-get update && apt-get install -y libsdl2-dev sox alsa-utils mpg123

WORKDIR /app

COPY . .

RUN make

CMD ["./build/beatbot"]
