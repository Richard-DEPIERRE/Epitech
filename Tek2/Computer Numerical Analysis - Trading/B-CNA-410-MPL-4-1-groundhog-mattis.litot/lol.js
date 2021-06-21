window.onload = function () {
    var secondes = 0;
    var millisecondes = 0;
    var docSecondes = document.getElementById("seconde");
    var docMillisecondes = document.getElementById("milliseconde");
    var start = document.getElementById("start");
    var stop = document.getElementById("stop");
    var restart = document.getElementById("restart");
    var Interval

    start.onclick = function() {
        clearInterval(Interval);
        Interval = setInterval(startTimer, 10);
    }

    stop.onclick = function() {
        clearInterval(Interval);
    }
      
    restart.onclick = function() {
        clearInterval(Interval);
        secondes = 0;
        millisecondes = 0;
        docSecondes.innerHTML = "00";
        docMillisecondes.innerHTML = "00";
    }

    function startTimer () {
        millisecondes++;
        
        if (millisecondes <= 9) {
            docMillisecondes.innerHTML = "0" + millisecondes;
        } else {
            docMillisecondes.innerHTML = millisecondes;
        }
        
        if (millisecondes > 99) {
            secondes++;
            if (secondes <= 9) {
                docSecondes.innerHTML = "0" + secondes;
            } else {
                docSecondes.innerHTML = secondes;
            }
            millisecondes = 0;
            docMillisecondes.innerHTML = "0" + 0;
        }
    }
}