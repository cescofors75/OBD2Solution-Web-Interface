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
          ['Label', 'xxx1'],
          ['Speed', 80],
          ['RPM * 100', 55],
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
      
        var  y = parseFloat(this.responseText);

          data.setValue(0, 1, y);
          chart.draw(data, options);
        }
  };
  xhttp.open("GET", "/readSPEED", true);
  xhttp.send();
     }, 100);
setInterval(function() {var xhttp = new XMLHttpRequest();
  xhttp.onreadystatechange = function() {
    if (this.readyState == 4 && this.status == 200) {
     
          var y = parseFloat(this.responseText);

          data.setValue(1, 1, y/100);
          chart.draw(data, options);
        }
  };
  xhttp.open("GET", "/readRPM", true);
  xhttp.send();
     
   }, 100);


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

<div id="chart_div"></div>

<div id="chart_div2"></div>

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





</div>
</body>
</html>
)=====";

