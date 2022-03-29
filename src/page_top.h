


const char PAGE_Top[] PROGMEM = R"=====(
<!DOCTYPE html>
<html>
<head>
  
<meta charset="utf-8" />
<meta name="viewport" content="width=device-width,initial-scale=1">
 
 
  <link rel="stylesheet" href="http://ajax.googleapis.com/ajax/libs/jqueryui/1.8.16/themes/base/jquery-ui.css" type="text/css" media="all" />
  <link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/3.4.1/css/bootstrap.min.css">
  <link rel="stylesheet" href="http://192.168.50.12/obd_style.css">
  <link rel="stylesheet" href="https://www.w3schools.com/w3css/4/w3.css">

  <script src="http://ajax.googleapis.com/ajax/libs/jqueryui/1.8.16/jquery-ui.min.js" type="text/javascript"></script>
  <script src="https://ajax.googleapis.com/ajax/libs/jquery/3.5.1/jquery.min.js"></script>
  <script src="https://maxcdn.bootstrapcdn.com/bootstrap/3.4.1/js/bootstrap.min.js"></script>



<script>



 
    

       function getTop(){
      
        var xhttp = new XMLHttpRequest();
        xhttp.onreadystatechange = function() {
        if (this.readyState == 4 && this.status == 200) {
        document.getElementById("reftop").innerHTML =
        this.responseText;
          }
         };
       xhttp.open("GET", "/readTop", true);
       xhttp.send();
      }
     
      

   

   
</script>

<style>
img:hover {
  opacity: 0.6;
  

}
</style> 

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
      <li class="active"><a href="/">Home</a></li>
      <li class="dropdown"><a class="dropdown-toggle" data-toggle="dropdown" href="#">Codes <span class="caret"></span></a>
        <ul class="dropdown-menu">
          <li><a href="/pageDtcs">List codes</a></li>
          <li><a href="/pageSolution">Codes - Solution</a></li>
          <li><a href="/ClearDTC">Clear codes</a></li>
          
          

        </ul>
      </li>
      <li class="dropdown"><a class="dropdown-toggle" data-toggle="dropdown" href="#">Table Codes <span class="caret"></span></a>
        <ul class="dropdown-menu">
          <li><a href="/pageList">Standard codes</a></li>
          <li><a href="/pageListF">Ford codes</a></li>
          <li><a href="/pageListH">Honda codes</a></li>
          <li><a href="/pageListT">Toyota codes</a></li>
          <li><a href="/pageListC">Jeep-Chrysler codes</a></li>
          <li><a href="/pageListG">General Motors codes</a></li>

        </ul>
      </li>
      <li><a href="/pageGauges">Displays</a></li>
      
      
      <li class="dropdown"><a class="dropdown-toggle" data-toggle="dropdown" href="#">VIN <span class="caret"></span></a>
      <ul class="dropdown-menu">
      
      <li><a href="/pageVin">Enter VIN number</a></li>
      <li><a href="/pageAVin">Automatic VIN</a></li>
      
      
	    </ul>
      </li>

      <li class="dropdown"><a class="dropdown-toggle" data-toggle="dropdown" href="#">Catalogue-Parts <span class="caret"></span></a>
      <ul class="dropdown-menu">
      <li><a href="/pageParts">Catalogue VIN</a></li>
      <li><a href="/pageParts2">Catalologue ALL</a></li>
      </ul>
      </li>

     
     <li class="dropdown"><a class="dropdown-toggle" data-toggle="dropdown" href="#">Lang <span class="caret"></span></a>
        <ul class="dropdown-menu">
          <li><a href="#">FR</a></li>
          <li><a href="#">EN</a></li>
          <li><a href="#">ES</a></li>
        </ul>
      </li>
    
      
     
    </ul>
  </div>
</nav>






<div id="recomendado" style="font-family : 'JetBrains Mono';">
 <h3><span id="reftop">Waiting ...</span></h3>
</div>
</div>








<div class="info">
<div  style="display: inline-block;">
<a href="/pageDtcs">
<img src="http://192.168.50.12/buttons/read.jpg" style="box-shadow: 0 0 15px #999;" width="120" height="120"></a>
</div>
<div  style="display: inline-block;">
<a href="/pageSolution">
<img src="http://192.168.50.12/buttons/solution.jpg" style="box-shadow: 0 0 15px #999;" width="120" height="120"></a>
</div>

<div  style="display: inline-block;">
<a href="#" data-toggle="modal" data-target="#exampleModal">
<img src="http://192.168.50.12/buttons/clear.jpg" style="box-shadow: 0 0 15px #999;" width="120" height="120"></a>



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
<img src="http://192.168.50.12/buttons/live.jpg" style="box-shadow: 0 0 15px #999;" width="120" height="120"></a>
</div>
<div  style="display: inline-block;">
<a href="/pageVin">
<img src="http://192.168.50.12/buttons/vin2.jpg" style="box-shadow: 0 0 15px #999;" width="120" height="120"></a>
</div>


<div  style="display: inline-block;">
<a href="/pageParts">
<img src="http://192.168.50.12/buttons/cat3.jpg" style="box-shadow: 0 0 15px #999;" width="120" height="120"></a>
</div>


</div>


<div class="info">
<button type="button" class="btn btn-primary" data-toggle="modal" data-target="#exampleModal2" href="#exampleModal2">
  Reset OBD2Solution
</button>

<!-- Modal -->
<div class="modal fade" id="exampleModal2" tabindex="-1" role="dialog" aria-labelledby="exampleModalLabel" aria-hidden="true">
  <div class="modal-dialog" role="document">
    <div class="modal-content">
      <div class="modal-header">
        <h5 class="modal-title" id="exampleModalLabel">Warning</h5>
        <button type="button" class="close" data-dismiss="modal" aria-label="Close">
          <span aria-hidden="true">&times;</span>
        </button>
      </div>
      <div class="modal-body">
       Are you sure you want to reset OBD2Solution ? 
      </div>
      <div class="modal-footer">
        <button type="button" class="btn btn-secondary" data-dismiss="modal">Cancel</button>
        <button type="button" class="btn btn-primary" onclick="window.location.href='/Reset'">Reset</button>
      </div>
    </div>
  </div>
</div>


</div>


</div>









<script>
getTop();
</script>



</body>
</html>
)=====";

