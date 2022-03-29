const char PAGE_Gauges[] PROGMEM = R"=====(
<html>
<head>
 <style>
.page{

    max-width: 100%;
    margin: auto;
  }
  .info{
      font-family: "Trebuchet MS", Verdana, Arial, Helvetica, sans-serif;
      max-width: 100%;
       min-height: 160px;
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
  <script type="text/javascript" src="https://www.gstatic.com/charts/loader.js"></script>
<script type="text/javascript">
      google.charts.load('current', {'packages':['gauge']});
      google.charts.setOnLoadCallback(drawChart);
    function drawChart() {

        var data = google.visualization.arrayToDataTable([
          ['Label', 'Value'],
          ['Speed', 80],
          ['RPM', 55],
          ['Temp1', 68],
          ['Temp2', 40]
        ]);
       
        var data2 = google.visualization.arrayToDataTable([
          ['Label', 'Value'],
          ['Fuel', 20],
          ['Voltage', 25],
          ['Temp3', 28],
          ['Temp4', 20]
        ]);

        var options = {
          width: 1200, height: 360,
          redFrom: 90, redTo: 100,
          yellowFrom:75, yellowTo: 90,
          minorTicks: 5
        };
       
        var chart = new google.visualization.Gauge(document.getElementById('chart_div'));
        var chart2 = new google.visualization.Gauge(document.getElementById('chart_div2'));
      setInterval(function() {var xhttp = new XMLHttpRequest();
       xhttp.onreadystatechange = function() {
    if (this.readyState == 4 && this.status == 200) {
      var x = (new Date()).getTime(),
          y = parseFloat(this.responseText);

          data.setValue(0, 1, y);
          chart.draw(data, options);
        }
  };
  xhttp.open("GET", "/readSPEED", true);
  xhttp.send();
     }, 1);
setInterval(function() {var xhttp = new XMLHttpRequest();
  xhttp.onreadystatechange = function() {
    if (this.readyState == 4 && this.status == 200) {
      var x = (new Date()).getTime(),
          y = parseFloat(this.responseText);

          data.setValue(1, 1, y);
          chart.draw(data, options);
        }
  };
  xhttp.open("GET", "/readRPM", true);
  xhttp.send();
     
   }, 1);


        setInterval(function() {
          data.setValue(2, 1, 60 + Math.round(20 * Math.random()));
          chart.draw(data, options);
        }, 260);
         setInterval(function() {
          data.setValue(3, 1, 60 + Math.round(20 * Math.random()));
          chart.draw(data, options);
        }, 260);
     
     
      setInterval(function() {
          data2.setValue(0, 1, 40 + Math.round(60 * Math.random()));
          chart2.draw(data2, options);
        }, 3000);

        setInterval(function() {
          data2.setValue(1, 1, 50 + Math.round(60 * Math.random()));
          chart2.draw(data2, options);
        }, 500);

         setInterval(function() {
          data2.setValue(2, 1, 50 + Math.round(60 * Math.random()));
          chart2.draw(data2, options);
        }, 500);

         setInterval(function() {
          data2.setValue(3, 1, 80 + Math.round(20 * Math.random()));
          chart2.draw(data2, options);
        }, 2600);
           }
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
<table style="border:1px solid black;margin-left:auto;margin-right:auto;">
<tr>
<td>
<div id="chart_div" style="width: 100%; height: 100%;"></div>
</td>
</tr>
<tr>
<td>
<div id="chart_div2" style="width: 100%; height: 100%;"></div>
</td>
</tr>
</table>
</div>
</div>
</body>
</html>
)=====";