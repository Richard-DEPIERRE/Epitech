const readline = require('readline');
var gameSettings = {
    timebank: null,
    time_per_move: null,
    player_names: null,
    your_bot: null,
    candle_interval: null,
    candle_format: null,
    candles_total: null,
    candles_given: null,
    initial_stack: null,
};
var check = 0
var stack_ETH = 0
var stack_BTC = 0
var stack_USDT = 0
var candlesBTC_ETH = new Array()
var candlesUSDT_BTC = new Array()
var candlesUSDT_ETH = new Array()

var io = readline.createInterface(process.stdin, process.stdout);
io.on('line', handleLine.bind(this));
io.on('close', handleIOClose.bind(this));

function handleLine(data) {
    if (data.length == 0)
        return;
    words = data.split(' ');
    // console.error(words);
    if (words[0] == "settings") {
        if (words[1] == "timebank")
            gameSettings.timebank = parseInt(words[2])
        if (words[1] == "time_per_move")
            gameSettings.time_per_move = parseInt(words[2])
        if (words[1] == "candle_interval")
            gameSettings.candle_interval = parseInt(words[2])
        if (words[1] == "candles_total")
            gameSettings.candles_total = parseInt(words[2])
        if (words[1] == "candles_given")
            gameSettings.candles_given = parseInt(words[2])
        if (words[1] == "initial_stack") {
            gameSettings.initial_stack = parseInt(words[2])
            stack_USDT = parseInt(words[2])
        }
        if (words[1] == "transaction_fee_percent")
            gameSettings.transaction_fee_percent = parseFloat(words[2])
        if (words[1] == "candle_format")
            gameSettings.candle_format = words[2]
    }
    if (words[0] == "update")
        if (words[1] == "game")
            if (words[2] == "next_candles") {
                coins = words[3].split(';')
                checkCandles(coins[0].split(','))
                checkCandles(coins[1].split(','))
                checkCandles(coins[2].split(','))
            }
            if (words[2] == "stacks") {
                all = words[3].split(',')
                for (i = 0; i < 3; i++) {
                    all_coin = all[i].split(':')
                    if (all_coin[0] == "BTC")
                        stack_BTC = (parseInt(all_coin[1])).toFixed(2)
                    if (all_coin[0] == "ETH")
                        stack_ETH = (parseInt(all_coin[1])).toFixed(2)
                    if (all_coin[0] == "USDT")
                        stack_USDT = parseInt(all_coin[1])
                }

            }
    if (words[0] == "action")
        if (words[1] == "order") {
            check = 0;
            checkBuyOrSell(candlesUSDT_ETH, stack_USDT, stack_ETH, "USDT_ETH");
            // checkBuyOrSell(candlesUSDT_BTC, stack_USDT, stack_BTC, "USDT_BTC", 0.1, 0.8);
            // checkBuyOrSell(candlesBTC_ETH, stack_BTC, stack_ETH, "BTC_ETH", 0.8, 0.8);
            if (check == 1) {
                console.log("pass")
            }
        }
}

function handleIOClose() {
    process.exit(0);
}

class MyCandles {
    constructor() {
        this.candle_pair = ""
        this.candle_date = 0
        this.candle_high = 0
        this.candle_low = 0
        this.candle_open = 0
        this.candle_close = 0
        this.candle_volume = 0
    }
    setPair(pair) {
        this.candle_pair = pair
    }
    setDate(date) {
        this.candle_date = date
    }
    setHigh(high){
        this.candle_high = high
    }
    setLow(low){
        this.candle_low = low
    }
    setOpen(open_){
        this.candle_open = open_
    }
    setClose(close_){
        this.candle_close = close_
    }
    setVolume(volume){
        this.candle_volume = volume
    }
    getPair(){
        return this.candle_pair
    }
    getDate(){
        return this.candle_date
    }
    getHigh(){
        return this.candle_high
    }
    getLow(){
        return this.candle_low
    }
    getOpen(){
        return this.candle_open
    }
    getClose(){
        return this.candle_close
    }
    getVolume(){
        return this.candle_volume
    }
}

function checkCandles(candles) {
    var steps = gameSettings.candle_format.split(',')
    var candle = new MyCandles()
    for (i = 0; i < steps.length; i++) {
        if ("pair" == steps[i]) {
            candle.setPair(candles[i])
        }
        if ("date" == steps[i]) {
            candle.setDate(parseInt(candles[i]))
        }
        if ("high" == steps[i]) {
            candle.setHigh(parseFloat(candles[i]))
        }
        if ("low" == steps[i]) {
            candle.setLow(parseFloat(candles[i]))
        }
        if ("open" == steps[i]) {
            candle.setOpen(parseFloat(candles[i]))
        }
        if ("close" == steps[i]) {
            candle.setClose(parseFloat(candles[i]))
        }
        if ("volume" == steps[i]) {
            candle.setVolume(parseFloat(candles[i]))
        }
    }
    if (candles[0] == "BTC_ETH")
        candlesBTC_ETH.push(candle)
    else if (candles[0] == "USDT_ETH")
        candlesUSDT_ETH.push(candle)
    else if (candles[0] == "USDT_BTC")
        candlesUSDT_BTC.push(candle)
}

function checkBuyOrSell(candles, stackone, stacktwo, name) {
    let open = 0
    let mean = 0
    let high = 0
    let low = 0
    let open_ = 0
    let mean_ = 0
    let high_ = 0
    let low_ = 0
    for (i = candles.length - 1; i > candles.length - 21; i--) {
        open += candles[i].getOpen()
        mean += candles[i].getClose()
        high += candles[i].getHigh()
        low += candles[i].getLow()
    }
    open /= 20
    mean /= 20
    high /= 20
    low /= 20
    for (i = candles.length - 1; i > candles.length - 5; i--) {
        open_ += (candles[i].getOpen() > open) ? 1 : -1;
        mean_ += (candles[i].getClose() > mean) ? 1 : -1;
        high_ += (candles[i].getHigh() > high) ? 1 : -1;
        low_ += (candles[i].getLow() > low) ? 1 : -1;
    }
    total = open_ + mean_ + high_ + low_;
    if (total >= 0) {
        var spend = stackone * (total / 40);
        var amt = spend/candles[candles.length - 1].getClose();
        if (amt > 0) {
            console.log("buy " + name + " " + amt)
        } else {
            check++
        }
    } else {
        var spend = stacktwo * ((total * -1) / 20);
        if (spend > 0) {
            console.log("sell " + name + " " + spend)
        } else {
            check++
        }
    }
}