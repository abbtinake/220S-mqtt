import mqtt from "mqtt/dist/mqtt";

const options = {
  port:5050,
  clientId: "tindra1",
  clean: false,
};

let client = mqtt.connect("ws:aedes-broker.cloud.mustini.se", options); // create a client

export { client };
