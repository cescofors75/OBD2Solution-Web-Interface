


const char PAGE_Open_AI[] PROGMEM = R"=====(
<!DOCTYPE html>
<html>



<head>
 

<meta charset="utf-8" />
<meta name="viewport" content="width=device-width, initial-scale=1">
  <link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/3.4.1/css/bootstrap.min.css">
  <link rel="stylesheet" href="http://192.168.50.12/obd_style.css">
  <script src="https://ajax.googleapis.com/ajax/libs/jquery/3.5.1/jquery.min.js"></script>
  <script src="https://maxcdn.bootstrapcdn.com/bootstrap/3.4.1/js/bootstrap.min.js"></script>
  
  
<script type="text/javascript">

    function getOpenAI() {
        var xhttp = new XMLHttpRequest();
        xhttp.onreadystatechange = function() {
        if (this.readyState == 4 && this.status == 200) {
        document.getElementById("OpenAI").innerHTML =
        this.responseText;
          }
         };
       xhttp.open("GET", "/OpenAI", true);
       xhttp.send();
      }
     
    

 
</script>

<script>
setInterval(function() {
  // Call a function repetatively with 5 Second interval
  getOpenAI();
}, 15000); 
 
</script>
</head>
<body>
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



<div class="info"> 
<div class="card">
  <span id="OpenAI">Loading AI </span>
</div>
</div>

 
</div>
</body>
</html>
)=====";

const char PAGE_All_catalogue[] PROGMEM = R"=====(
<!DOCTYPE html>
<html>



<head>
 <style>
     
tbody tr:nth-child(odd) {
  background-color: #f0f4fc;
  font-family: "Trebuchet MS", Verdana, Arial, Helvetica, sans-serif;
    font-size: 16px;
}

tbody tr:nth-child(even) {
  background-color: #e3e5e8;
  font-family: "Trebuchet MS", Verdana, Arial, Helvetica, sans-serif;
    font-size: 16px;
}
.page{

    max-width: 90%;
    margin: auto;
  }
  .card{
      font-family: "Trebuchet MS", Verdana, Arial, Helvetica, sans-serif;
      max-width: 100%;
       min-height: 400px;
       
       background: #012d4f;
       font-size: 20px;  
       padding: 10px;
       box-sizing: border-box;
       color: #FFF;
       margin:10px;
       box-shadow: 0px 2px 18px -4px rgba(0,0,0,0.75);
  }
  .card2{
      font-family: "Trebuchet MS", Verdana, Arial, Helvetica, sans-serif;
      max-width: 100%;
       min-height: 120px;
       background: #000000;
       padding: 10px;
       box-sizing: border-box;
       color: #FFF;
       margin:10px;
       box-shadow: 0px 2px 18px -4px rgba(0,0,0,0.75);
  }
  
  .info{
      font-family: "Trebuchet MS", Verdana, Arial, Helvetica, sans-serif;
      max-width: 100%;
       min-height: 400px;
       background: #FFF;
       padding: 10px;
       box-sizing: border-box;
       color: #000;
       margin:10px;
       box-shadow: 0px 2px 18px -4px rgba(0,0,0,0.75);
       
 
  }

</style>

<meta charset="utf-8" />
<meta name="viewport" content="width=device-width, initial-scale=1">
  <link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/3.4.1/css/bootstrap.min.css">
  <script src="https://ajax.googleapis.com/ajax/libs/jquery/3.5.1/jquery.min.js"></script>
  <script src="https://maxcdn.bootstrapcdn.com/bootstrap/3.4.1/js/bootstrap.min.js"></script>
  
  

</head>
<body>
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




<iframe src="http://172.20.10.12/2022/worldparts.php"frameborder="0" style="overflow:hidden;overflow-x:hidden;overflow-y:hidden;height:100%;width:100%;position:absolute;top:0px;left:0px;right:0px;bottom:0px" height="100%" width="100%"</iframe>




 
</div>
</body>
</html>
)=====";