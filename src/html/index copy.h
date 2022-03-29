


const char MAIN_page[] PROGMEM = R"=====(

<!DOCTYPE html>
<html>
<head>


<style type="text/css">

html, body, #main {
  font-size: 16px;
  width: 100%;
  height: 100%;
  background:-webkit-linear-gradient(-45deg,  #a9e4f7 0%,#0fb4e7 100%);
}
#main{
 
  overflow: auto;
  box-sizing: border-box;
  padding-top:2rem;
}

.navbar{
  background-color:#222;
  border:1px solid grey;
  z-index: 1;
 position:absolute;
  top:50%;
  left:50%;
  transform:translate(-50%,-50%);
  box-shadow: 1px 1px 5px rgba(0,0,0,.5);
}

.navbar-default .navbar-nav > li > a{
  color:#fff;
  padding:15px 15px;
  outline:none;
}

.navbar-nav>li>.dropdown-menu {
  border-radius:6px;
}

.navbar-default .navbar-nav > li > a:hover{
  color:#121212;
  background-color:#fff;
}

.navbar-default .navbar-nav>.open>a, .navbar-default .navbar-nav>.open>a:focus, .navbar-default .navbar-nav>.open>a:hover {
    color: #fff;
    background-color: #000;

}

.dropdown-menu>li>a:hover {
    color: #c9c3c3;
    text-decoration: none;
    background-color: #121212;
}

.navbar-default .navbar-nav>.active>a, .navbar-default .navbar-nav>.active>a:focus, .navbar-default .navbar-nav>.active>a:hover {
    color: #fff;
    background-color: #d71919;
}

.dropdown-menu>li>a {
    color: #000;
}

@media screen and (max-width:768px) and (min-width:100px) {
  
  .main{
    width:25%;
  }
 .navbar-default .navbar-nav > li > a {
    color: #fff;
    outline: none;
   overflow:hidden;
}
  .navbar {
  overflow:hidden;
    width:25%;
}
  .navbar ul li{
    position:relative;
  }
    .navbar ul li a{
      margin-left: 15px;
      
    }
    .navbar ul li:active {
   color:green;
    }
  
  
  .navbar-nav .open .dropdown-menu {
    position: static;
    float: none;
    width: auto;
    margin-top: 0;
    background-color: transparent;
    border: 0;
    -webkit-box-shadow: none;
    box-shadow: none;
}
  
.navbar-nav .open .dropdown-menu>li:hover a{
    
    background-color: transparent;
  margin-left:18px;
  color:#fff !important;
  
}
  .navbar-nav .open .dropdown-menu>li:hover:before{
    font:normal normal normal 14px/1 FontAwesome;
    content:'\f054';
     width:10px;
    height:10px;
    position:absolute;
    left:18%;
    top:46%;
    transform:translate(-50%,-50%);
    color:#e14444;
 
    
  }
  
  
  .navbar-default .navbar-nav .open .dropdown-menu>li>a {
    color: #e14444;
}
}
</style>






<link rel="stylesheet" href="http://ajax.googleapis.com/ajax/libs/jqueryui/1.8.16/themes/base/jquery-ui.css" type="text/css" media="all" />
<link rel="stylesheet" href="http://192.168.50.12/obd2style.css" type="text/css" media="all" />
<script src="http://ajax.googleapis.com/ajax/libs/jquery/1.6.2/jquery.min.js" type="text/javascript"></script>
<script src="http://ajax.googleapis.com/ajax/libs/jqueryui/1.8.16/jquery-ui.min.js" type="text/javascript"></script>
 <script>
 $(function() {
 $('#tabs').tabs();
 });
 </script>

<script type="text/javascript">

    function getMake() {
        var xhttp = new XMLHttpRequest();
        xhttp.onreadystatechange = function() {
        if (this.readyState == 4 && this.status == 200) {
        document.getElementById("MakeValue").innerHTML =
        this.responseText;
          }
         };
       xhttp.open("GET", "readMake", true);
       xhttp.send();
      }
     
    function getPIDS(){
      
        var xhttp = new XMLHttpRequest();
        xhttp.onreadystatechange = function() {
        if (this.readyState == 4 && this.status == 200) {
        document.getElementById("PIDSValue").innerHTML =
        this.responseText;
          }
         };
       xhttp.open("GET", "readPIDS", true);
       xhttp.send();
      }
     

    $( '.navbar-nav a' ).on( 'click', function () {
	  $( '.navbar-nav' ).find( 'li.active' ).removeClass( 'active' );
	  $( this ).parent( 'li' ).addClass( 'active' );
    });  

   

   
</script>

   

  </head>





<body>
<div class="content">

<div id="main">
<nav class="navbar navbar-default">
  <ul class="nav navbar-nav">
    <li><a href="#0">Home</a></li>
    <li><a href="#0">About</a></li>
    <li class="dropdown">
      <a href="#0" class="dropdown-toggle" data-toggle="dropdown" data-target="dropdown" role="button" aria-haspopup="true" aria-expanded="false">Clients<span class="caret"></span></a>
      <ul class="dropdown-menu" id="dropdon-menu">
        <li><a href="#0">Burger King</a></li>
        <li><a href="#0">Southwest Airlines</a></li>
        <li><a href="#0">Levi Strauss</a></li>
      </ul>
    </li>
    <li class="dropdown">
      <a href="#0" class="dropdown-toggle" data-toggle="dropdown" data-target="dropdown" role="button" aria-haspopup="true" aria-expanded="false">Services<span class="caret"></span></a>
      <ul class="dropdown-menu" id="dropdon-menu">
        <li><a href="#0">Print Design</a></li>
        <li><a href="#0">Web Design</a></li>
        <li><a href="#0">Mobile App Development</a></li>
      </ul>
    </li>
    <li><a href="#0">Contact</a></li>
  </ul>
</nav>
</div>






<div class="navbar">
  <a href="/">INFO</a>
  <a href="/pageGauges">DISPLAY-GAUGES</a>
  <a href="/pageDtcs">DTCS</a>
  <a href="/pageParts">PARTS-CATALOGUE</a>
</div>
<div><br><br><br></div>
<div class="info"> 
<div class="card">
  <h2><span id="MakeValue">LOADING</span></h2>
</div>
</div>


<script>

setInterval(function() {
  // Call a function repetatively with 2 Second interval
  getMake();
}, 2000); //2000mSeconds update rate


</script>



<div id="tabs">
<ul>
 <li><a href="#tabs-1">ENGINE</a></li>
 <li><a href="#tabs-2">AIR / FUEL </a></li>
 <li><a href="#tabs-3">TEMP</a></li>
 <li><a href="#tabs-4">SPEED / TIME</a></li>
 <li><a href="#tabs-5">DRIVER</a></li>
 <li><a href="#tabs-6">ELECTRIC SYSTEMS</a></li>
 </ul>
<div id="tabs-1">
<h2><span id="PIDSValue">LOADING</span></h2>

 </div>
 <div id="tabs-2">
 <p>PID_COOLANT_TEMP – Engine coolant temperature (°C)</p>
 <p>PID_ENGINE_OIL_TEMP – Engine oil temperature (°C)</p>
 </div>
 <div id="tabs-3">
 <p>PID_INTAKE_TEMP – Intake temperature (°C)</p>
 <p>PID_INTAKE_PRESSURE – Intake manifold absolute pressure (kPa)</p>
 <p>PID_MAF_FLOW – MAF flow pressure (grams/s)</p>
 <p>PID_BAROMETRIC – Barometric pressure (kPa)</p>
 </div>
 <div id="tabs-4">
 <p>PID_SPEED – Vehicle speed (km/h)</p>
 <p>PID_RUNTIME – Engine running time (second)</p>
 <p>PID_DISTANCE – Vehicle running distance (km)</p>
 </div>
 <div id="tabs-5">
 <p>PID_THROTTLE – Throttle position (%)</p>
 <p>PID_AMBIENT_TEMP – Ambient temperature (°C)</p>
 </div>
 <div id="tabs-6">
 <p>PID_CONTROL_MODULE_VOLTAGE</p>
 <p>PID_HYBRID_BATTERY_PERCENTAGE</p>
 </div>
</div>
<script> $('#linkToTab3').click(function() { 
 // To get the index of the currently selected Tab ;
// var index = $('#tabs').data('tabs').options.selected; ;
// alert('selected tab = ' + index); ;
// To set the index of the tab to be selected ;
$('#tabs').tabs('select', 2); }); </script>

<script>


setInterval(function() {
  // Call a function repetatively with 2 Second interval
  getPIDS();
},2000); //2000mSeconds update rate


</script>



</div>
</body>
</html>
)=====";