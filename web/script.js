const APPID = "Theif";
const KEY = "pYZUu6WKOki5f5S";
const SECRET = "0TspHzjdYtkTigX6JktBj0Ofo";
const ALIAS = "HTML_web";
const thing = "NodeMCU";
var maxNum = maxNum;
var curNum = 0;
var microgear = Microgear.create({
    key: KEY,
    secret: SECRET,
    alias: ALIAS
});
function getCurNum(){
    return curNum;
}
microgear.on('message', function(topic,msg) {
    document.getElementById("curPeople").innerHTML = msg;
    document.getElementById("raw_data").innerHTML = "msg:" + msg;
});
microgear.on('connected', function() {
    microgear.setAlias(ALIAS);
    console.log("Connected to NETPIE.")
});
microgear.on('present', function(event) {
    console.log(event);
});
microgear.on('absent', function(event) {
    console.log(event);
});
microgear.resettoken(function(err){
    microgear.connect(APPID)
});