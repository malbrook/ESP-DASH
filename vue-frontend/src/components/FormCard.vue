<template>
    <!-- Slider Card -->
     <!-- Made by Malcolm Brook -->
     <!-- GitHub Profile: https://github.com/malbrook -->
     <!-- Based on 'vue-slider-component' by NightCatSama https://github.com/NightCatSama -->
    <div class="column is-2">
        <div class="card">
            <header><h5>{{name}}</h5></header>
            <vue-slider
                ref="slider"
                v-model="value1"
                style="display: inline-block; margin: 30px;"
                v-bind="options"
                @change="setValue"
                @drag-end="sendValue"
            ></vue-slider>
            <h2>Setting: {{value}}</h2>
        </div>
    </div>
</template>

<script>
    import VueSlider from 'vue-slider-component'
    import EventBus from '@/event-bus.js';
    import { setTimeout } from 'timers';
    
    export default {
        props:{
            id: String, 
            name: String, 
            direction: String, 
            value: Number
        },
        
        data () {
            return {
                activity: true,
                msg:"",
                options: {
                    dotSize: 50,
                    width: 35,
                    contained: false,
                    data: null,
                    direction:"btt",
                    height:200,
                    min: 0,
                    max: 100,
                    interval: 1,
                    disabled: false,
                    clickable: true,
                    duration: 0.5,
                    adsorb: false,
                    lazy: false,
                    tooltip: 'focus',
                    tooltipPlacement: 'top',
                    tooltipFormatter: void 0,
                    useKeyboard: false,
                    enableCross: true,
                    fixed: false,
                    minRange: void 0,
                    maxRange: void 0,
                    order: true,
                    marks: false,
                    dotOptions: void 0,
                    process: true,
                    dotStyle: void 0,
                    railStyle: void 0,
                    processStyle: void 0,
                    tooltipStyle: void 0,
                    stepStyle: void 0,
                    stepActiveStyle: void 0,
                    labelStyle: void 0,
                    labelActiveStyle: void 0,
                }
            }
        },
        watch: { 
        //    value:function() {
        //        this.value1 = this.value
        //        this.activity = true;
        //        setTimeout(() => {this.activity = false}, 100);
        //        
        //    }
            
        },

        methods: {
            setValue(){
                this.value = this.value1;
            },
            sendValue() {
                this.msg = this.id + "-" + this.value1;
                EventBus.$emit('sliderChanged', this.msg);
                this.activity = true;
                setTimeout(() => { this.activity = false }, 100);                
            }
       },
       mounted () {
            setTimeout(() => { this.activity = false }, 500);
       },
       components: {
            VueSlider
        }
    }
</script>
<style>
/* component style */
.vue-slider-disabled .vue-slider-rail {
  background-color: #ccc;
}
.vue-slider-disabled .vue-slider-dot-handle {
  background-color: #666;
}
.vue-slider-disabled .vue-slider-process {
  background-color: #666;
}
.vue-slider-disabled .vue-slider-mark-step {
  background-color: #666;
}
.vue-slider-disabled .vue-slider-mark-step-active {
  background-color: #ccc;
}

/* rail style */
.vue-slider-rail {
  background-color: #bda1f3;
  border-radius: 15px;
}

/* process style */
.vue-slider-process {
  background-color: #6200ee;
  border-radius: 15px;
}

/* mark style */
.vue-slider-mark {
  z-index: 4;
}
.vue-slider-mark-step {
  width: 100%;
  height: 100%;
  border-radius: 50%;
  background-color: #6200ee;
}
.vue-slider-mark-step-active {
  background-color: #bda1f3;
}

.vue-slider-mark-label {
  font-size: 14px;
  white-space: nowrap;
}
/* dot style */
.vue-slider-dot-handle {
  cursor: pointer;
  position: relative;
  width: 100%;
  height: 100%;
  border-radius: 50%;
  background-color: #6200ee;
  box-sizing: border-box;
}
.vue-slider-dot-handle::after {
  content: "";
  position: absolute;
  left: 50%;
  top: 50%;
  width: 200%;
  height: 200%;
  background-color: rgba(98, 0, 238, 0.38);
  border-radius: 50%;
  transform: translate(-50%, -50%) scale(0);
  z-index: -1;
  transition: transform 0.2s;
}
.vue-slider-dot-handle-focus::after {
  transform: translate(-50%, -50%) scale(1);
}

.vue-slider-dot-handle-disabled {
  cursor: not-allowed;
  background-color: #666 !important;
}

.vue-slider-dot-tooltip {
  visibility: visible;
}
.vue-slider-dot-tooltip-show .vue-slider-dot-tooltip-inner {
  opacity: 1;
}
.vue-slider-dot-tooltip-show .vue-slider-dot-tooltip-inner-top {
  transform: rotateZ(-45deg);
}
.vue-slider-dot-tooltip-show .vue-slider-dot-tooltip-inner-bottom {
  transform: rotateZ(135deg);
}
.vue-slider-dot-tooltip-show .vue-slider-dot-tooltip-inner-left {
  transform: rotateZ(-135deg);
}
.vue-slider-dot-tooltip-show .vue-slider-dot-tooltip-inner-right {
  transform: rotateZ(45deg);
}

.vue-slider-dot-tooltip-inner {
  border-radius: 50% 50% 50% 0px;
  background-color: #6200ee;
  opacity: 0;
  transition: transform 0.4s cubic-bezier(0.25, 0.8, 0.25, 1), opacity 0.2s linear;
}
.vue-slider-dot-tooltip-inner-top {
  transform: translate(0, 50%) scale(0.01) rotate(-45deg);
}
.vue-slider-dot-tooltip-inner-bottom {
  transform: translate(0, -50%) scale(0.01) rotateZ(135deg);
}
.vue-slider-dot-tooltip-inner-left {
  transform: translate(50%, 0) scale(0.01) rotateZ(-135deg);
}
.vue-slider-dot-tooltip-inner-right {
  transform: translate(-50%, 0) scale(0.01) rotateZ(45deg);
}
.vue-slider-dot-tooltip-text {
  font-size: 12px;
  white-space: nowrap;
  text-align: center;
  color: #fff;
  width: 30px;
  height: 30px;
  display: flex;
  align-items: center;
  justify-content: center;
  box-sizing: content-box;
}

.vue-slider-dot-tooltip-inner-top .vue-slider-dot-tooltip-text {
  transform: rotateZ(45deg);
}
.vue-slider-dot-tooltip-inner-bottom .vue-slider-dot-tooltip-text {
  transform: rotateZ(-135deg);
}
.vue-slider-dot-tooltip-inner-left .vue-slider-dot-tooltip-text {
  transform: rotateZ(135deg);
}
.vue-slider-dot-tooltip-inner-right .vue-slider-dot-tooltip-text {
  transform: rotateZ(-45deg);
}

/*# sourceMappingURL=material.css.map */
</style>