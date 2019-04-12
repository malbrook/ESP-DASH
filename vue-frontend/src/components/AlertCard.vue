<template>
    <!-- 
    # Alert Card - display icon and a user message 
    # Made by Malcolm Brook
    # GitHub Profile: https://github.com/malbrook
    # Based on  
    -->
    <div class="column is-2">
      <div class="card">
        <span class="dot" :class="{'active': activity}"></span>
        <div class="card-content">
          <header><h5>{{name}}</h5></header>
          <Br/>
          <p>
          
            <ok-check-icon class="active" v-if="value == 0"></ok-check-icon>                    // all clear
            <alert-octagon-icon class="warning" v-else-if="value == 1"></alert-octagon-icon>    // minor problem, auto recover
            <alert-triangle-icon class="alert" v-else-if="value == 2"></alert-triangle-icon>   // severe problem needs user intervention
            <x-icon class="danger" v-else-if="value == 3"></x-icon>                            // program error  report to support
            <span>{message}</span>
          </p>
        </div>
      </div>
    </div>
</template>

<script>
import { CheckCircleIcon, XCircleIcon, AlertOctagonIcon, PauseCircleIcon } from 'vue-feather-icons';

export default {
    props:['name', 'value', 'message'],
    components:{
        OkCheckIcon,
        AlertOctagonIcon,
        AlertTriangleIcon,
        XIcon
    },

    data(){
      return{
        activity: true
      }
    },

    watch: { 
        value: function() {
        this.activity = true;
        setTimeout(() => {this.activity = false}, 100);
      }
    },

    mounted(){
      setTimeout(() => { this.activity = false }, 500);
    }
}
</script>

<style scoped>
.card svg{
  width: 64px;
  height: 64px;
  color:grey;
}

.card svg.active{
  color:green;
}

.card svg.warning{
  color: rgb(221, 221, 59);
}
.card svg.alert{
  color: rgb(239, 133, 26);
}


.card svg.danger{
 color: rgb(211, 44, 46);
}



</style>
