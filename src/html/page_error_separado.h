


const char PAGE_Error_1[] PROGMEM = R"=====(





<!DOCTYPE html>
<html>



<head>
<style type="text/css">
.test {
      text-decoration: none;

    }
.button3 {
  display: block;
  margin-left: auto;
  margin-right: auto;  
  background-color: #bd0416; /* red */
  border: none;
  color: white;
  padding: 15px 32px;
  text-align: center;
  text-decoration: none;
  
  font-size: 20px;
}
</style>

<link rel="stylesheet" href="http://192.168.50.12/obd2style.css" type="text/css" media="all" />
<link rel="stylesheet" href="http://ajax.googleapis.com/ajax/libs/jqueryui/1.8.16/themes/base/jquery-ui.css" type="text/css" media="all" />
  
   <script src="http://ajax.googleapis.com/ajax/libs/jquery/1.6.2/jquery.min.js" type="text/javascript"></script>
 <script src="http://ajax.googleapis.com/ajax/libs/jqueryui/1.8.16/jquery-ui.min.js" type="text/javascript"></script>
 

<script type="text/javascript">

    function getMake() {
        var xhttp = new XMLHttpRequest();
        xhttp.onreadystatechange = function() {
        if (this.readyState == 4 && this.status == 200) {
        document.getElementById("MakeValue").innerHTML =
        this.responseText;
          }
         };
       xhttp.open("GET", "/readMake", true);
       xhttp.send();
      }
     
    

   function getInfo(){
      
        var xhttp = new XMLHttpRequest();
        xhttp.onreadystatechange = function() {
        if (this.readyState == 4 && this.status == 200) {
        document.getElementById("InfoValue").innerHTML =
        this.responseText;
          }
         };
       xhttp.open("GET", "/readError", true);
       xhttp.send();
      }

      function PostClearDTC(){

              var xhttp = new XMLHttpRequest();
              
              

               
            xhttp.open("GET", "/ClearDTC", true);
               xhttp.send();

      }

function getidCar(){
      
        var xhttp = new XMLHttpRequest();
        xhttp.onreadystatechange = function() {
        if (this.readyState == 4 && this.status == 200) {
        document.getElementById("idCar").innerHTML =
        this.responseText;
          }
         };
       xhttp.open("GET", "/idCar", true);
       xhttp.send();
      }











   
</script>

   

  </head>





<body>
<div class="content">

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





<div class="info">
<div class="card2">
 <h2><span id="InfoValue">LOADING DTC. </span></h2>
 </div>
 </div> 
 <div class="info">
 <a href="https://api.whatsapp.com/send?phone=+34618900003&text=
 )=====";
 
 
 const char PAGE_Error_2[] PROGMEM = R"=====(
 " style="display: table; font-family: sans-serif; text-decoration: none; text-aling : left; margin: 1em auto; color: #fff; font-size: 0.9em; padding: 1em 2em 1em 3.5em; border-radius: 2em; font-weight: bold; background: #25d366 url('https://tochat.be/click-to-chat-directory/css/whatsapp.svg') no-repeat 1.5em center; background-size: 1.6em;">Contacto con tu Profesional</a>
 </div> 
 <div class="info">
 <a class="test" href="ClearDTC"><button class="button3">CLEAR DTC </button></a>

 </div>
 

 


<div class="info">
<div class="card3">
 <h2><span id="idCar">LOADING . </span></h2>
  
 </div>
 </div>
<script>
setInterval(function() {
  // Call a function repetatively with 2 Second interval
  getMake();
}, 5000); //2000mSeconds update rate
setInterval(function() {
  // Call a function repetatively with 2 Second interval
  getInfo();
}, 5000); //2000mSeconds update rate

setInterval(function() {
  // Call a function repetatively with 2 Second interval
  getidCar();
}, 5000); //2000mSeconds update rate




</script>






</div>
</body>
</html>
)=====";