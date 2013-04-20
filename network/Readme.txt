author: machao

The work has two parts, the server and the client(in separate folders) 
---------------------------------------------------------------------------------

1. client
(1)The client program needs 3 parameters -- hostname port page

(2)sample input is:
./client 127.0.0.1 8000 /index.html (the page has to be in the form of /filename)

sample output is:
HTTP/1.1 200 OK
Server: MaChaoServer
Content-Length: 2221
Content-Type: text/html
Last-Modified: 15/04/2013 17:55:30 

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 4.0 Strict//EN"
"http://www.w3.org/TR/xhtml/DTD/xhtml1-strict.dtd">
<html xmlns = "http://www.w3.org/1999/xhtml" lang = "en" xml:lang = "en">
  <head>
    <meta http-equiv="Content-Type" content="text/html; charset=ISO-8859-1">
    <title>Charles Ma's Homepage!</title>
    <link type = "text/css" rel = "stylesheet" href = "css/main.css"/>
  </head>
  <body>
    <div id = "middle_area">
      <h1 id = "welcome_title">Welcome to Charles' Homepage!</h1>
      <ul class = "outline">
      <li>Who's Charles?</li>
      <li>What does he do?</li>
      <li>How to contact him?</li>
      <li>What's happening in the IT world now?</li>
      <li>What's happening in Upenn now?</li>
      </ul>
      <p id = "eniac_p">
      <a href="http://www.linkedin.com/in/chaoma">CONNECT ME ON LINKED IN!!!!!!</a>
      <!--This is a comment-->
      </p>
      <p id = "google_p">
      This is a link to <a href="http://www.google.com">Google</a>
      </p>
      <p id = "wiki_p">
      This is an introduction to <q>ENIAC</q> on <a href="http://en.wikipedia.org/wiki/ENIAC">Wiki</a>
      </p>
      <p id = "resum_p">
      Here's my <a href="resume.pdf">resume</a>
      </p>
      <img id = "right_image" src="images/android_backpack.jpg" id = "squirrel">
    </div>
    <div id = "float_one">
    Coming Soon!!!
    </div>
    <div id = "float_two">
    Under Construction...
    </div>
    <script type = "text/javascript">
      var flag = 1;
      var moving_area_1 = document.getElementById("float_one");
      var moving_area_2 = document.getElementById("float_two");
      moving_area_1.style.left = "0px";
      distance = screen.width/2;
      moving_area_2.style.left = distance + parseInt(moving_area_1.style.left) + "px";
      var my_time_out = setInterval("floating();", 15);
      function floating()
      {
         change_position(moving_area_1);
         change_position(moving_area_2);
      }
      function change_position(moving_area)
      {
         var x = parseInt(moving_area.style.left);
         if(x <= -100){
	       flag = 1;
	        }
		 if(x >= 200){
		          flag = 0;
			   }
			   if(flag == 1){
			     x = screen.width;
			     }
			     if(flag == 0){
			       x -= 1;
			       }
			       moving_area.style.left = x+"px";
      }
    </script>
  </body>
</html>

(3)The client has the ability to cache visited websites. It stores the websites in the folder "temp"(make sure this folder is available before run client)

(4)If you make run the program, the client will use 127.0.0.1 as IP address and port 8000, the requested page is /index.html

-------------------------------------------------------------------------------------------------------
   
2. server
(1)The server can give the requested file to the client

(2)In the server directory, there are 3 sample htmls.

(3)The server will create the server_log.txt to keep track of server actions

(4)If you make run the program, the server will use port 8000

