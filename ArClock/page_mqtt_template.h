/*
 * MqClock
 * 
 * (c) Robert Pelczarski 2021
 */
 
#pragma once

/**************************************************************************/

const char page_mqtt_template[] PROGMEM = R""(<!DOCTYPE html>
<html>

  <head>
  
    <title>MqClock</title>

    <link rel="stylesheet" href="/pure-min.css">
    <link rel="stylesheet" href="/grids-responsive-min.css">
    <meta name="viewport" content="width=device-width, initial-scale=1">    

    <link rel="icon" href="data:image/png;base64,iVBORw0KGgoAAAANSUhEUgAAACAAAAAgCAYAAABzenr0AAAE9ElEQVRYR+1We2xTVRz+fvd2bdmDuZZtsOG2lgwBhYCKEJwOdThEBcY7iGEKHcISiJigjDfCfEXJiCPSAhlBzMDJY9EBAgIKRFwUAghkSLvBNvag3VzXre167zG33ZCt7bgYEmLC+fOc7/d93/nu75xzCQ940APWx0MDDxP4fyUwGlAk66PGksiNI8IwBtZbOkUEqmEMZxknllw1Nxw8Dnjkni7ZCWQlRs0ER+sA0nVPzsoZseUmc8NOOSbuauDN2NgwdWhbAYGm3EkYFspBE6XwTtkaPHC0iJ30GFiRsyUkc0dtraM7I90ayEyCWkmaQwA9L5HwPJDyTARSRkQgvn9/ILyvj7u5ElVlZTh5xo6Tv9khCB2S7Gc3s6UXlMMZzES3BrKStNtAeEsq7qVRYN7sWMSNnIq2frPAwuIhOFu8vLw6FOSoQsi1r1H967fYvL0Wt2ztbcCwzVhunXPPBgwJ2jTi8aPUY1GRPJYs0iHspY8hxDx7m6vmWDGICLGjX789x9edguPoB/g0z4KGv71RMCbgZdN165FAJoImYNBpThLIq7b4nd5ImvY5hD4vduK48uVKEHF4LHt1p3n+5k8o3/0evviqxjvPwE6ZLLYU2QYM+oj+xJRXpN0/MaAHFuRMhmv4Z37159fOB4gwZMUmvzVV6RJsyi3CxSutvhTIPcBktpd1BQZMwKDXLiCGfAk8941oDJlnghA9wk/kQu5C79zgnI1+a3z9GZzfbMCWnfW+FAjZJrPVz2lgAzptPgELpMKPlidCPeMEwKv+FWEMbY4mWHZsBCkUSDYs9U9XcMFZmIql6yraPwM2mSzWbHkJ6DS7CDRNAudveBLusT9469rsjagqKUTjxVJ4mptwvdaKuPSpGDl7fsAmVx58Fdnv/tHRB7tNFtt0WQay9Nq9YJgogfM+GQRxvNTAvrBaa26g8UIpnLWVQHQ8NMNSEBkTG8AAA1echkXvX/KtEfYZzdYMWQYMSdpjRBgtgXMWxSFmdglYj0AiATfu02utRd32ccjNq/YlwHDcVG59QZaBLJ3mGkB6CTw+/RGMWbgKHv2M4GoBVhTmQhzeuAbFhxrbV5nZaLH1u6uB7PgIbZtSWQeAk8DSJbRm1TAIYwoBRZg8Ex4H+MMzsGrN2Y7LSKoTQ9zumPwqu/VOEr9TYEjUvE0cbb0TlJbaE5PmZsD11HqA+O5NMAGq35dhz5a9OHKiqROWiWyOqcK2LaiBrLi4UKhc5wAkd1WZPkGD1Ix0uIcuA1NpA5oglxXKc+txYu8h7NpvC4S5CpdqqLG62veIdLT2Zugjq6PtgxvULFckPBdsi6OGh2PCxHiEDHwNQswosDDfa0iOSvB1p9F2+Xvs31eF06XNQVPiGH6JclJOcn3k+Vn4q4m2olcEpwitIiBCzgdWqAkJTyvRZ7AS4b28bYLmWyJuXnDjeqkbHheTQwMG2EVPSzytBrjoHn33OBXiBFmV9wmk9nD761srJ3mbMCtRsxYcrbhP3PJoRPahscK20mdApy0CMFle5X1DfWe0WKf4DCRpL4EwMBA1k55z4BuQeAACBf216lTLMzUY9wqAmdRxh3clZ7hsLLcOogI+wWRXCZkM8P1hdhkejh1d3Fyd9l/2vSE87jAvUsBaAjw9XXwBFSgSLgJ4PLgAO5jpuSHt5p5HgeLRAwCN7abwz38Avh23Yy35j3MAAAAASUVORK5CYII=">

    <link href="https://fonts.googleapis.com/css2?family=Montserrat&display=swap" rel="stylesheet">

    <script>let timezone = "{{timezone}}";</script>
    <script src="/script.js"></script>
    
  </head>
  <body style="padding:0.8em; font-family: 'Montserrat', sans-serif;">
  
    <h1><center>Sensor MqClock - MQTT/Sequence</center></h1>
    <form id="form_sens" class="pure-form pure-form-aligned">
      <fieldset>
          <legend>Sensor topics</legend>
            <div class="pure-control-group">
            <label for="q1">q1</label>
            <input type="text" name="q1" value="{{q1}}" onChange="updateSingle(this)">{{v1}}
            <div class="pure-control-group">
            <label for="q2">q2</label>
            <input type="text" name="q2" value="{{q2}}" onChange="updateSingle(this)">{{v2}}
            <div class="pure-control-group">
            <label for="q3">q3</label>
            <input type="text" name="q3" value="{{q3}}" onChange="updateSingle(this)">{{v3}}
            <div class="pure-control-group">
            <label for="q4">q4</label>
            <input type="text" name="q4" value="{{q4}}" onChange="updateSingle(this)">{{v4}}
            <div class="pure-control-group">
            <label for="q5">q5</label>
            <input type="text" name="q5" value="{{q5}}" onChange="updateSingle(this)">{{v5}}
            <div class="pure-control-group">
            <label for="q6">q6</label>
            <input type="text" name="q6" value="{{q6}}" onChange="updateSingle(this)">{{v6}}
          </div>
      </fieldset>
      <fieldset>
          <legend>Sequence</legend>
            <div class="pure-control-group">
            <label for="d">Delay</label>
            <input type="text" name="d" value="{{d}}" onChange="updateSingle(this)">
            </div>
            <div class="pure-control-group">
            <label for="aSeq">Default animations between steps</label>
            <input type="text" name="aSeq" value="{{aSeq}}" onChange="updateSingle(this)"><span>[x|y|d]{to|delay}:{from}[,]</span>
            </div>
            <div class="pure-control-group">
            <label for="sequence">Sequence</label>
            <input type="text" name="sequence" value="{{sequence}}" style="width: 80%" onChange="updateSingle(this)">
            <div>; - settings separator, | - sequence separator, ex. d=5;pFmt=i2H!:M|a=X0:-32;pFmt=S i1</div>
            </div>
      </fieldset>
      <a class="pure-button" style="background: rgb(255, 120, 30);" onClick="save();">Save</a>
    </form>
    <a href="/">Main page</a>
  </body>
</html>
)""

/**************************************************************************/
;
