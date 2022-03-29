const char PAGE_Vin[] PROGMEM = R"=====(
<!DOCTYPE html>
<html>
<head>
  
<meta charset="utf-8" />
<meta name="viewport" content="width=device-width, initial-scale=1 ">
  <link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/3.4.1/css/bootstrap.min.css">
  <link rel="stylesheet" href="http://172.20.10.10/obd_style.css">

  <script src="https://ajax.googleapis.com/ajax/libs/jquery/3.5.1/jquery.min.js"></script>
  <script src="https://maxcdn.bootstrapcdn.com/bootstrap/3.4.1/js/bootstrap.min.js"></script>
  <link rel="stylesheet" href="http://ajax.googleapis.com/ajax/libs/jqueryui/1.8.16/themes/base/jquery-ui.css" type="text/css" media="all" />
  <script src="http://ajax.googleapis.com/ajax/libs/jqueryui/1.8.16/jquery-ui.min.js" type="text/javascript"></script>
  
 
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
<form action="/get">
    Enter a VIN number (manual): <input type="text" name="input_string">
    <input type="submit" value="OK">
  </form><br>


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






</body>
</html>
)=====";

const char Page_Reset[] PROGMEM = R"=====(
<!DOCTYPE html>
<html>
<head>
  
<meta charset="utf-8" />
<meta name="viewport" content="width=device-width, initial-scale=1 "/>
<meta http-equiv="refresh" content="2;url='http://obd2.local/'"/>

  <link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/3.4.1/css/bootstrap.min.css"/>
  <link rel="stylesheet" href="http://172.20.10.10/obd_style.css"/>
  <link rel="stylesheet" href="http://ajax.googleapis.com/ajax/libs/jqueryui/1.8.16/themes/base/jquery-ui.css" type="text/css" media="all" />

  <script src="https://ajax.googleapis.com/ajax/libs/jquery/3.5.1/jquery.min.js"></script>
  <script src="https://maxcdn.bootstrapcdn.com/bootstrap/3.4.1/js/bootstrap.min.js"></script>
  <script src="http://ajax.googleapis.com/ajax/libs/jqueryui/1.8.16/jquery-ui.min.js" type="text/javascript"></script>
  
 
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

<div class="info2">
<h3>

Resetting the system <br>
This operation may take 10 seconds
 
</h3>


</div>





</body>
</html>
)=====";