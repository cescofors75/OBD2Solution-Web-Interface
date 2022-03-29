


const char PAGE_Error_S[] PROGMEM = R"=====(
<!DOCTYPE html>
<html>



<head>
 

<meta charset="utf-8" />
<meta name="viewport" content="width=device-width, initial-scale=1">
  <link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/3.4.1/css/bootstrap.min.css">
  <link rel="stylesheet" href="http://172.20.10.10/obd_style.css">
  <script src="https://ajax.googleapis.com/ajax/libs/jquery/3.5.1/jquery.min.js"></script>
  <script src="https://maxcdn.bootstrapcdn.com/bootstrap/3.4.1/js/bootstrap.min.js"></script>
  <link rel="stylesheet" href="http://ajax.googleapis.com/ajax/libs/jqueryui/1.8.16/themes/base/jquery-ui.css" type="text/css" media="all" />
  <script src="http://ajax.googleapis.com/ajax/libs/jqueryui/1.8.16/jquery-ui.min.js" type="text/javascript"></script>
  <link rel="stylesheet" href="https://www.w3schools.com/w3css/4/w3.css">
  
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

<script>
setInterval(function() {
  // Call a function repetatively with 2 Second interval
  getMake();
}, 5000); //2000mSeconds update rate

setInterval(function() {
  // Call a function repetatively with 2 Second interval
  getInfo();
}, 5000); //2000mSeconds update rate




</script>



   

</head>





<body>
<div class="loader-wrapper">
      <span class="loader"><span class="loader-inner"></span></span>
    </div>
    <script>
        $(window).on("load",function(){
          $(".loader-wrapper").fadeOut("slow");
        });
    </script>
<div class="page">
<nav class="navbar navbar-inverse">
  <div class="container-fluid">
    <div class="navbar-header">
      <a class="navbar-brand" href="/">OBD2Solution</a>
    </div>
    <ul class="nav navbar-nav">
      <li class="active"><a href="/">Inicio</a></li>
      <li class="dropdown"><a class="dropdown-toggle" data-toggle="dropdown" href="#">Errores <span class="caret"></span></a>
        <ul class="dropdown-menu">
          <li><a href="/pageDtcs">Ver Errores</a></li>
          <li><a href="/pageSolution">Errores - Solución</a></li>
          
          <li><a href="/pageList">Listado Errores Generales</a></li>
           <li><a href="/pageListF">Listado Errores FORD</a></li>
          <li><a href="/ClearDTC">Borrar Errores</a></li>

        </ul>
      </li>
      <li><a href="/pageGauges">Displays</a></li>
      
      
      <li class="dropdown"><a class="dropdown-toggle" data-toggle="dropdown" href="#">VIN <span class="caret"></span></a>
      <ul class="dropdown-menu">
      <li><a href="/pageVin">Manual VIN</a></li>
      <li><a href="/pageAVin">Automatic VIN</a></li>
	    </ul>
      </li>

      <li class="dropdown"><a class="dropdown-toggle" data-toggle="dropdown" href="#">Catalogos <span class="caret"></span></a>
      <ul class="dropdown-menu">
      <li><a href="/pageParts">Catalogo VIN</a></li>
      <li><a href="/pageParts2">Catalogo ALL</a></li>
      </ul>
      </li>

     
     <li class="dropdown"><a class="dropdown-toggle" data-toggle="dropdown" href="#">Idioma <span class="caret"></span></a>
        <ul class="dropdown-menu">
          <li><a href="#">FR</a></li>
          <li><a href="#">EN</a></li>
          <li><a href="#">ES</a></li>
        </ul>
      </li>
     
      
    </ul>
  </div>
</nav>



<div class="info"> 
<div class="card">
  <h3><span id="MakeValue">Waiting ... </span></h3>
</div>
</div>





<div class="info">

 <h3><span id="InfoValue">Waiting ...</span></h3>

 </div> 
 <script>
 getidCar();
 </script>


 


 <div class="info">
<div class="card3">
 <h3><span id="idCar"> </span></h3>
  </div>
 </div>

<div class="info">
<div  style="display: inline-block;">
<a href="/pageDtcs">
<img src="http://172.20.10.10/buttons/read.jpg" style="box-shadow: 0 0 15px #999;" width="120" height="120"></a>
</div>
<div  style="display: inline-block;">
<a href="/pageSolution">
<img src="http://172.20.10.10/buttons/solution.jpg" style="box-shadow: 0 0 15px #999;" width="120" height="120"></a>
</div>

<div  style="display: inline-block;">
<a href="#" data-toggle="modal" data-target="#exampleModal">
<img src="http://172.20.10.10/buttons/clear.jpg" style="box-shadow: 0 0 15px #999;" width="120" height="120"></a>



<!-- Modal -->
<div class="modal fade" id="exampleModal" tabindex="-1" role="dialog" aria-labelledby="exampleModalLabel" aria-hidden="true">
  <div class="modal-dialog" role="document">
    <div class="modal-content">
      <div class="modal-header">
        <h5 class="modal-title" id="exampleModalLabel">Warning</h5>
        <button type="button" class="close" data-dismiss="modal" aria-label="Close">
          <span aria-hidden="true">&times;</span>
        </button>
      </div>
      <div class="modal-body">
       Are you sure you want to clear codes ?
      </div>
      <div class="modal-footer">
        <button type="button" class="btn btn-secondary" data-dismiss="modal">Cancel</button>
        <button type="button" class="btn btn-primary" onclick="window.location.href='/ClearDTC'">Clear</button>
      </div>
    </div>
  </div>
</div>
</div>
<div  style="display: inline-block;">
<a href="/pageGauges">
<img src="http://172.20.10.10/buttons/live.jpg" style="box-shadow: 0 0 15px #999;" width="120" height="120"></a>
</div>
<div  style="display: inline-block;">
<a href="/pageVin">
<img src="http://172.20.10.10/buttons/vin2.jpg" style="box-shadow: 0 0 15px #999;" width="120" height="120"></a>
</div>


<div  style="display: inline-block;">
<a href="/pageParts">
<img src="http://172.20.10.10/buttons/cat3.jpg" style="box-shadow: 0 0 15px #999;" width="120" height="120"></a>
</div>


</div>











 <div class="info">
    <div class="card3">
        <br><br>
 <a href='https://api.whatsapp.com/send?phone=34618900003&text=
 )=====";
 
 
 const char PAGE_Error_S2[] PROGMEM = R"=====(
 target="_blank"; style=" font-family: sans-serif; 
 text-decoration: none; margin: 1em auto; color: #fff; 
 font-size: 0.9em; padding: 1em 2em 1em 3.5em; border-radius: 2em; 
 font-weight: bold; 
 background: #25d366 url('https://tochat.be/click-to-chat-directory/css/whatsapp.svg') no-repeat 1.5em center; 
 background-size: 1.6em;">Contacto con tu Profesional</a>
</div>
</div>
</div>






</body>
</html>
)=====";