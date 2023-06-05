<template>
  <q-page class="bg-grey-3">
    <Joystick
    :size="100"
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
const stop = () => console.log('stop')
const move = ({ x, y, direction, distance }) => {
  client.publish("tindra/direction", String(direction));
  client.publish("tindra/distance", String(distance));
}

onMounted(() => {
  client.on("connect", () => {
    console.log("Conntected!")
    client.subscribe("tindra/distance","tindra/direction", function (err) {
    })
  })
})

client.on("message", (topic, message) => {
  // console.log(`${topic} - ${message.toString()}`)
  let info = JSON.parse(message)
})


const distance = (b) => {
  client.publish("tindra/distance", info)
}

const direction = (a) => {
  let info = JSON.stringify("hej")
  client.publish("tindra/direction", info)
}

</script>
