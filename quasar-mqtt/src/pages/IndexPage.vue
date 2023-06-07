<template>
  <q-page class="bg-grey-3">
    <Joystick class="fixed-center"
    :size="400"
    base-color="lightblue"
    stick-color="orange"
    :throttle="100"
    @start="start"
    @stop="stop"
    @move="move"
  />
  </q-page>
</template>

<script setup>
import { client } from "src/boot/mqtt-boot"
import { ref, onMounted } from 'vue'
import Joystick from 'vue-joystick-component'

const start = () => console.log('start')
const stop = () => {console.log('stop')
  client.publish("tindra/turning", 'FORWARD');
  client.publish("tindra/throttle", String(0.0));}
const move = ({ x, y, direction, distance }) => {
  client.publish("tindra/turning", String(direction));
  client.publish("tindra/throttle", String(distance));
}

onMounted(() => {
  client.on("connect", () => {
    console.log("Conntected!")
    client.subscribe("tindra/throttle","tindra/turning", function (err) {
    })
  })
})

client.on("message", (topic, message) => {
  // console.log(`${topic} - ${message.toString()}`)
  let info = JSON.parse(message)
})


const throttle = (b) => {
  client.publish("tindra/throttle", info)
}

const turning = (a) => {
  let info = JSON.stringify("hej")
  client.publish("tindra/turning", info)
}

</script>
