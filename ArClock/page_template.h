/*
 * ArClock
 * 
 * (c) Matt Aubury 2020
 */
 
#pragma once

/**************************************************************************/

/*
 * From: https://unpkg.com/purecss@2.0.3/build/pure-min.css
 */
const char pure_min_css[] PROGMEM = R""(
/*!
Pure v2.0.3
Copyright 2013 Yahoo!
Licensed under the BSD License.
https://github.com/pure-css/pure/blob/master/LICENSE.md
*/
/*!
normalize.css v | MIT License | git.io/normalize
Copyright (c) Nicolas Gallagher and Jonathan Neal
*/
/*! normalize.css v8.0.1 | MIT License | github.com/necolas/normalize.css */html{line-height:1.15;-webkit-text-size-adjust:100%}body{margin:0}main{display:block}h1{font-size:2em;margin:.67em 0}hr{-webkit-box-sizing:content-box;box-sizing:content-box;height:0;overflow:visible}pre{font-family:monospace,monospace;font-size:1em}a{background-color:transparent}abbr[title]{border-bottom:none;text-decoration:underline;-webkit-text-decoration:underline dotted;text-decoration:underline dotted}b,strong{font-weight:bolder}code,kbd,samp{font-family:monospace,monospace;font-size:1em}small{font-size:80%}sub,sup{font-size:75%;line-height:0;position:relative;vertical-align:baseline}sub{bottom:-.25em}sup{top:-.5em}img{border-style:none}button,input,optgroup,select,textarea{font-family:inherit;font-size:100%;line-height:1.15;margin:0}button,input{overflow:visible}button,select{text-transform:none}[type=button],[type=reset],[type=submit],button{-webkit-appearance:button}[type=button]::-moz-focus-inner,[type=reset]::-moz-focus-inner,[type=submit]::-moz-focus-inner,button::-moz-focus-inner{border-style:none;padding:0}[type=button]:-moz-focusring,[type=reset]:-moz-focusring,[type=submit]:-moz-focusring,button:-moz-focusring{outline:1px dotted ButtonText}fieldset{padding:.35em .75em .625em}legend{-webkit-box-sizing:border-box;box-sizing:border-box;color:inherit;display:table;max-width:100%;padding:0;white-space:normal}progress{vertical-align:baseline}textarea{overflow:auto}[type=checkbox],[type=radio]{-webkit-box-sizing:border-box;box-sizing:border-box;padding:0}[type=number]::-webkit-inner-spin-button,[type=number]::-webkit-outer-spin-button{height:auto}[type=search]{-webkit-appearance:textfield;outline-offset:-2px}[type=search]::-webkit-search-decoration{-webkit-appearance:none}::-webkit-file-upload-button{-webkit-appearance:button;font:inherit}details{display:block}summary{display:list-item}template{display:none}[hidden]{display:none}html{font-family:sans-serif}.hidden,[hidden]{display:none!important}.pure-img{max-width:100%;height:auto;display:block}.pure-g{letter-spacing:-.31em;text-rendering:optimizespeed;font-family:FreeSans,Arimo,"Droid Sans",Helvetica,Arial,sans-serif;display:-webkit-box;display:-ms-flexbox;display:flex;-webkit-box-orient:horizontal;-webkit-box-direction:normal;-ms-flex-flow:row wrap;flex-flow:row wrap;-ms-flex-line-pack:start;align-content:flex-start}@media all and (-ms-high-contrast:none),(-ms-high-contrast:active){table .pure-g{display:block}}.opera-only :-o-prefocus,.pure-g{word-spacing:-.43em}.pure-u{display:inline-block;letter-spacing:normal;word-spacing:normal;vertical-align:top;text-rendering:auto}.pure-g [class*=pure-u]{font-family:sans-serif}.pure-u-1,.pure-u-1-1,.pure-u-1-12,.pure-u-1-2,.pure-u-1-24,.pure-u-1-3,.pure-u-1-4,.pure-u-1-5,.pure-u-1-6,.pure-u-1-8,.pure-u-10-24,.pure-u-11-12,.pure-u-11-24,.pure-u-12-24,.pure-u-13-24,.pure-u-14-24,.pure-u-15-24,.pure-u-16-24,.pure-u-17-24,.pure-u-18-24,.pure-u-19-24,.pure-u-2-24,.pure-u-2-3,.pure-u-2-5,.pure-u-20-24,.pure-u-21-24,.pure-u-22-24,.pure-u-23-24,.pure-u-24-24,.pure-u-3-24,.pure-u-3-4,.pure-u-3-5,.pure-u-3-8,.pure-u-4-24,.pure-u-4-5,.pure-u-5-12,.pure-u-5-24,.pure-u-5-5,.pure-u-5-6,.pure-u-5-8,.pure-u-6-24,.pure-u-7-12,.pure-u-7-24,.pure-u-7-8,.pure-u-8-24,.pure-u-9-24{display:inline-block;letter-spacing:normal;word-spacing:normal;vertical-align:top;text-rendering:auto}.pure-u-1-24{width:4.1667%}.pure-u-1-12,.pure-u-2-24{width:8.3333%}.pure-u-1-8,.pure-u-3-24{width:12.5%}.pure-u-1-6,.pure-u-4-24{width:16.6667%}.pure-u-1-5{width:20%}.pure-u-5-24{width:20.8333%}.pure-u-1-4,.pure-u-6-24{width:25%}.pure-u-7-24{width:29.1667%}.pure-u-1-3,.pure-u-8-24{width:33.3333%}.pure-u-3-8,.pure-u-9-24{width:37.5%}.pure-u-2-5{width:40%}.pure-u-10-24,.pure-u-5-12{width:41.6667%}.pure-u-11-24{width:45.8333%}.pure-u-1-2,.pure-u-12-24{width:50%}.pure-u-13-24{width:54.1667%}.pure-u-14-24,.pure-u-7-12{width:58.3333%}.pure-u-3-5{width:60%}.pure-u-15-24,.pure-u-5-8{width:62.5%}.pure-u-16-24,.pure-u-2-3{width:66.6667%}.pure-u-17-24{width:70.8333%}.pure-u-18-24,.pure-u-3-4{width:75%}.pure-u-19-24{width:79.1667%}.pure-u-4-5{width:80%}.pure-u-20-24,.pure-u-5-6{width:83.3333%}.pure-u-21-24,.pure-u-7-8{width:87.5%}.pure-u-11-12,.pure-u-22-24{width:91.6667%}.pure-u-23-24{width:95.8333%}.pure-u-1,.pure-u-1-1,.pure-u-24-24,.pure-u-5-5{width:100%}.pure-button{display:inline-block;line-height:normal;white-space:nowrap;vertical-align:middle;text-align:center;cursor:pointer;-webkit-user-drag:none;-webkit-user-select:none;-moz-user-select:none;-ms-user-select:none;user-select:none;-webkit-box-sizing:border-box;box-sizing:border-box}.pure-button::-moz-focus-inner{padding:0;border:0}.pure-button-group{letter-spacing:-.31em;text-rendering:optimizespeed}.opera-only :-o-prefocus,.pure-button-group{word-spacing:-.43em}.pure-button-group .pure-button{letter-spacing:normal;word-spacing:normal;vertical-align:top;text-rendering:auto}.pure-button{font-family:inherit;font-size:100%;padding:.5em 1em;color:rgba(0,0,0,.8);border:none transparent;background-color:#e6e6e6;text-decoration:none;border-radius:2px}.pure-button-hover,.pure-button:focus,.pure-button:hover{background-image:-webkit-gradient(linear,left top,left bottom,from(transparent),color-stop(40%,rgba(0,0,0,.05)),to(rgba(0,0,0,.1)));background-image:linear-gradient(transparent,rgba(0,0,0,.05) 40%,rgba(0,0,0,.1))}.pure-button:focus{outline:0}.pure-button-active,.pure-button:active{-webkit-box-shadow:0 0 0 1px rgba(0,0,0,.15) inset,0 0 6px rgba(0,0,0,.2) inset;box-shadow:0 0 0 1px rgba(0,0,0,.15) inset,0 0 6px rgba(0,0,0,.2) inset;border-color:#000}.pure-button-disabled,.pure-button-disabled:active,.pure-button-disabled:focus,.pure-button-disabled:hover,.pure-button[disabled]{border:none;background-image:none;opacity:.4;cursor:not-allowed;-webkit-box-shadow:none;box-shadow:none;pointer-events:none}.pure-button-hidden{display:none}.pure-button-primary,.pure-button-selected,a.pure-button-primary,a.pure-button-selected{background-color:#0078e7;color:#fff}.pure-button-group .pure-button{margin:0;border-radius:0;border-right:1px solid rgba(0,0,0,.2)}.pure-button-group .pure-button:first-child{border-top-left-radius:2px;border-bottom-left-radius:2px}.pure-button-group .pure-button:last-child{border-top-right-radius:2px;border-bottom-right-radius:2px;border-right:none}.pure-form input[type=color],.pure-form input[type=date],.pure-form input[type=datetime-local],.pure-form input[type=datetime],.pure-form input[type=email],.pure-form input[type=month],.pure-form input[type=number],.pure-form input[type=password],.pure-form input[type=search],.pure-form input[type=tel],.pure-form input[type=text],.pure-form input[type=time],.pure-form input[type=url],.pure-form input[type=week],.pure-form select,.pure-form textarea{padding:.5em .6em;display:inline-block;border:1px solid #ccc;-webkit-box-shadow:inset 0 1px 3px #ddd;box-shadow:inset 0 1px 3px #ddd;border-radius:4px;vertical-align:middle;-webkit-box-sizing:border-box;box-sizing:border-box}.pure-form input:not([type]){padding:.5em .6em;display:inline-block;border:1px solid #ccc;-webkit-box-shadow:inset 0 1px 3px #ddd;box-shadow:inset 0 1px 3px #ddd;border-radius:4px;-webkit-box-sizing:border-box;box-sizing:border-box}.pure-form input[type=color]{padding:.2em .5em}.pure-form input[type=color]:focus,.pure-form input[type=date]:focus,.pure-form input[type=datetime-local]:focus,.pure-form input[type=datetime]:focus,.pure-form input[type=email]:focus,.pure-form input[type=month]:focus,.pure-form input[type=number]:focus,.pure-form input[type=password]:focus,.pure-form input[type=search]:focus,.pure-form input[type=tel]:focus,.pure-form input[type=text]:focus,.pure-form input[type=time]:focus,.pure-form input[type=url]:focus,.pure-form input[type=week]:focus,.pure-form select:focus,.pure-form textarea:focus{outline:0;border-color:#129fea}.pure-form input:not([type]):focus{outline:0;border-color:#129fea}.pure-form input[type=checkbox]:focus,.pure-form input[type=file]:focus,.pure-form input[type=radio]:focus{outline:thin solid #129fea;outline:1px auto #129fea}.pure-form .pure-checkbox,.pure-form .pure-radio{margin:.5em 0;display:block}.pure-form input[type=color][disabled],.pure-form input[type=date][disabled],.pure-form input[type=datetime-local][disabled],.pure-form input[type=datetime][disabled],.pure-form input[type=email][disabled],.pure-form input[type=month][disabled],.pure-form input[type=number][disabled],.pure-form input[type=password][disabled],.pure-form input[type=search][disabled],.pure-form input[type=tel][disabled],.pure-form input[type=text][disabled],.pure-form input[type=time][disabled],.pure-form input[type=url][disabled],.pure-form input[type=week][disabled],.pure-form select[disabled],.pure-form textarea[disabled]{cursor:not-allowed;background-color:#eaeded;color:#cad2d3}.pure-form input:not([type])[disabled]{cursor:not-allowed;background-color:#eaeded;color:#cad2d3}.pure-form input[readonly],.pure-form select[readonly],.pure-form textarea[readonly]{background-color:#eee;color:#777;border-color:#ccc}.pure-form input:focus:invalid,.pure-form select:focus:invalid,.pure-form textarea:focus:invalid{color:#b94a48;border-color:#e9322d}.pure-form input[type=checkbox]:focus:invalid:focus,.pure-form input[type=file]:focus:invalid:focus,.pure-form input[type=radio]:focus:invalid:focus{outline-color:#e9322d}.pure-form select{height:2.25em;border:1px solid #ccc;background-color:#fff}.pure-form select[multiple]{height:auto}.pure-form label{margin:.5em 0 .2em}.pure-form fieldset{margin:0;padding:.35em 0 .75em;border:0}.pure-form legend{display:block;width:100%;padding:.3em 0;margin-bottom:.3em;color:#333;border-bottom:1px solid #e5e5e5}.pure-form-stacked input[type=color],.pure-form-stacked input[type=date],.pure-form-stacked input[type=datetime-local],.pure-form-stacked input[type=datetime],.pure-form-stacked input[type=email],.pure-form-stacked input[type=file],.pure-form-stacked input[type=month],.pure-form-stacked input[type=number],.pure-form-stacked input[type=password],.pure-form-stacked input[type=search],.pure-form-stacked input[type=tel],.pure-form-stacked input[type=text],.pure-form-stacked input[type=time],.pure-form-stacked input[type=url],.pure-form-stacked input[type=week],.pure-form-stacked label,.pure-form-stacked select,.pure-form-stacked textarea{display:block;margin:.25em 0}.pure-form-stacked input:not([type]){display:block;margin:.25em 0}.pure-form-aligned input,.pure-form-aligned select,.pure-form-aligned textarea,.pure-form-message-inline{display:inline-block;vertical-align:middle}.pure-form-aligned textarea{vertical-align:top}.pure-form-aligned .pure-control-group{margin-bottom:.5em}.pure-form-aligned .pure-control-group label{text-align:right;display:inline-block;vertical-align:middle;width:10em;margin:0 1em 0 0}.pure-form-aligned .pure-controls{margin:1.5em 0 0 11em}.pure-form .pure-input-rounded,.pure-form input.pure-input-rounded{border-radius:2em;padding:.5em 1em}.pure-form .pure-group fieldset{margin-bottom:10px}.pure-form .pure-group input,.pure-form .pure-group textarea{display:block;padding:10px;margin:0 0 -1px;border-radius:0;position:relative;top:-1px}.pure-form .pure-group input:focus,.pure-form .pure-group textarea:focus{z-index:3}.pure-form .pure-group input:first-child,.pure-form .pure-group textarea:first-child{top:1px;border-radius:4px 4px 0 0;margin:0}.pure-form .pure-group input:first-child:last-child,.pure-form .pure-group textarea:first-child:last-child{top:1px;border-radius:4px;margin:0}.pure-form .pure-group input:last-child,.pure-form .pure-group textarea:last-child{top:-2px;border-radius:0 0 4px 4px;margin:0}.pure-form .pure-group button{margin:.35em 0}.pure-form .pure-input-1{width:100%}.pure-form .pure-input-3-4{width:75%}.pure-form .pure-input-2-3{width:66%}.pure-form .pure-input-1-2{width:50%}.pure-form .pure-input-1-3{width:33%}.pure-form .pure-input-1-4{width:25%}.pure-form-message-inline{display:inline-block;padding-left:.3em;color:#666;vertical-align:middle;font-size:.875em}.pure-form-message{display:block;color:#666;font-size:.875em}@media only screen and (max-width :480px){.pure-form button[type=submit]{margin:.7em 0 0}.pure-form input:not([type]),.pure-form input[type=color],.pure-form input[type=date],.pure-form input[type=datetime-local],.pure-form input[type=datetime],.pure-form input[type=email],.pure-form input[type=month],.pure-form input[type=number],.pure-form input[type=password],.pure-form input[type=search],.pure-form input[type=tel],.pure-form input[type=text],.pure-form input[type=time],.pure-form input[type=url],.pure-form input[type=week],.pure-form label{margin-bottom:.3em;display:block}.pure-group input:not([type]),.pure-group input[type=color],.pure-group input[type=date],.pure-group input[type=datetime-local],.pure-group input[type=datetime],.pure-group input[type=email],.pure-group input[type=month],.pure-group input[type=number],.pure-group input[type=password],.pure-group input[type=search],.pure-group input[type=tel],.pure-group input[type=text],.pure-group input[type=time],.pure-group input[type=url],.pure-group input[type=week]{margin-bottom:0}.pure-form-aligned .pure-control-group label{margin-bottom:.3em;text-align:left;display:block;width:100%}.pure-form-aligned .pure-controls{margin:1.5em 0 0 0}.pure-form-message,.pure-form-message-inline{display:block;font-size:.75em;padding:.2em 0 .8em}}.pure-menu{-webkit-box-sizing:border-box;box-sizing:border-box}.pure-menu-fixed{position:fixed;left:0;top:0;z-index:3}.pure-menu-item,.pure-menu-list{position:relative}.pure-menu-list{list-style:none;margin:0;padding:0}.pure-menu-item{padding:0;margin:0;height:100%}.pure-menu-heading,.pure-menu-link{display:block;text-decoration:none;white-space:nowrap}.pure-menu-horizontal{width:100%;white-space:nowrap}.pure-menu-horizontal .pure-menu-list{display:inline-block}.pure-menu-horizontal .pure-menu-heading,.pure-menu-horizontal .pure-menu-item,.pure-menu-horizontal .pure-menu-separator{display:inline-block;vertical-align:middle}.pure-menu-item .pure-menu-item{display:block}.pure-menu-children{display:none;position:absolute;left:100%;top:0;margin:0;padding:0;z-index:3}.pure-menu-horizontal .pure-menu-children{left:0;top:auto;width:inherit}.pure-menu-active>.pure-menu-children,.pure-menu-allow-hover:hover>.pure-menu-children{display:block;position:absolute}.pure-menu-has-children>.pure-menu-link:after{padding-left:.5em;content:"\25B8";font-size:small}.pure-menu-horizontal .pure-menu-has-children>.pure-menu-link:after{content:"\25BE"}.pure-menu-scrollable{overflow-y:scroll;overflow-x:hidden}.pure-menu-scrollable .pure-menu-list{display:block}.pure-menu-horizontal.pure-menu-scrollable .pure-menu-list{display:inline-block}.pure-menu-horizontal.pure-menu-scrollable{white-space:nowrap;overflow-y:hidden;overflow-x:auto;padding:.5em 0}.pure-menu-horizontal .pure-menu-children .pure-menu-separator,.pure-menu-separator{background-color:#ccc;height:1px;margin:.3em 0}.pure-menu-horizontal .pure-menu-separator{width:1px;height:1.3em;margin:0 .3em}.pure-menu-horizontal .pure-menu-children .pure-menu-separator{display:block;width:auto}.pure-menu-heading{text-transform:uppercase;color:#565d64}.pure-menu-link{color:#777}.pure-menu-children{background-color:#fff}.pure-menu-disabled,.pure-menu-heading,.pure-menu-link{padding:.5em 1em}.pure-menu-disabled{opacity:.5}.pure-menu-disabled .pure-menu-link:hover{background-color:transparent}.pure-menu-active>.pure-menu-link,.pure-menu-link:focus,.pure-menu-link:hover{background-color:#eee}.pure-menu-selected>.pure-menu-link,.pure-menu-selected>.pure-menu-link:visited{color:#000}.pure-table{border-collapse:collapse;border-spacing:0;empty-cells:show;border:1px solid #cbcbcb}.pure-table caption{color:#000;font:italic 85%/1 arial,sans-serif;padding:1em 0;text-align:center}.pure-table td,.pure-table th{border-left:1px solid #cbcbcb;border-width:0 0 0 1px;font-size:inherit;margin:0;overflow:visible;padding:.5em 1em}.pure-table thead{background-color:#e0e0e0;color:#000;text-align:left;vertical-align:bottom}.pure-table td{background-color:transparent}.pure-table-odd td{background-color:#f2f2f2}.pure-table-striped tr:nth-child(2n-1) td{background-color:#f2f2f2}.pure-table-bordered td{border-bottom:1px solid #cbcbcb}.pure-table-bordered tbody>tr:last-child>td{border-bottom-width:0}.pure-table-horizontal td,.pure-table-horizontal th{border-width:0 0 1px 0;border-bottom:1px solid #cbcbcb}.pure-table-horizontal tbody>tr:last-child>td{border-bottom-width:0}
.hide {
  display:none;
}
.small {
  font-size: 70%;
}
)"";

/**************************************************************************/

/*
 * From https://unpkg.com/purecss@2.0.3/build/grids-responsive-min.css
 */
const char grids_responsive_min_css[] PROGMEM = R""(
/*!
Pure v2.0.3
Copyright 2013 Yahoo!
Licensed under the BSD License.
https://github.com/pure-css/pure/blob/master/LICENSE.md
*/
@media screen and (min-width:35.5em){.pure-u-sm-1,.pure-u-sm-1-1,.pure-u-sm-1-12,.pure-u-sm-1-2,.pure-u-sm-1-24,.pure-u-sm-1-3,.pure-u-sm-1-4,.pure-u-sm-1-5,.pure-u-sm-1-6,.pure-u-sm-1-8,.pure-u-sm-10-24,.pure-u-sm-11-12,.pure-u-sm-11-24,.pure-u-sm-12-24,.pure-u-sm-13-24,.pure-u-sm-14-24,.pure-u-sm-15-24,.pure-u-sm-16-24,.pure-u-sm-17-24,.pure-u-sm-18-24,.pure-u-sm-19-24,.pure-u-sm-2-24,.pure-u-sm-2-3,.pure-u-sm-2-5,.pure-u-sm-20-24,.pure-u-sm-21-24,.pure-u-sm-22-24,.pure-u-sm-23-24,.pure-u-sm-24-24,.pure-u-sm-3-24,.pure-u-sm-3-4,.pure-u-sm-3-5,.pure-u-sm-3-8,.pure-u-sm-4-24,.pure-u-sm-4-5,.pure-u-sm-5-12,.pure-u-sm-5-24,.pure-u-sm-5-5,.pure-u-sm-5-6,.pure-u-sm-5-8,.pure-u-sm-6-24,.pure-u-sm-7-12,.pure-u-sm-7-24,.pure-u-sm-7-8,.pure-u-sm-8-24,.pure-u-sm-9-24{display:inline-block;letter-spacing:normal;word-spacing:normal;vertical-align:top;text-rendering:auto}.pure-u-sm-1-24{width:4.1667%}.pure-u-sm-1-12,.pure-u-sm-2-24{width:8.3333%}.pure-u-sm-1-8,.pure-u-sm-3-24{width:12.5%}.pure-u-sm-1-6,.pure-u-sm-4-24{width:16.6667%}.pure-u-sm-1-5{width:20%}.pure-u-sm-5-24{width:20.8333%}.pure-u-sm-1-4,.pure-u-sm-6-24{width:25%}.pure-u-sm-7-24{width:29.1667%}.pure-u-sm-1-3,.pure-u-sm-8-24{width:33.3333%}.pure-u-sm-3-8,.pure-u-sm-9-24{width:37.5%}.pure-u-sm-2-5{width:40%}.pure-u-sm-10-24,.pure-u-sm-5-12{width:41.6667%}.pure-u-sm-11-24{width:45.8333%}.pure-u-sm-1-2,.pure-u-sm-12-24{width:50%}.pure-u-sm-13-24{width:54.1667%}.pure-u-sm-14-24,.pure-u-sm-7-12{width:58.3333%}.pure-u-sm-3-5{width:60%}.pure-u-sm-15-24,.pure-u-sm-5-8{width:62.5%}.pure-u-sm-16-24,.pure-u-sm-2-3{width:66.6667%}.pure-u-sm-17-24{width:70.8333%}.pure-u-sm-18-24,.pure-u-sm-3-4{width:75%}.pure-u-sm-19-24{width:79.1667%}.pure-u-sm-4-5{width:80%}.pure-u-sm-20-24,.pure-u-sm-5-6{width:83.3333%}.pure-u-sm-21-24,.pure-u-sm-7-8{width:87.5%}.pure-u-sm-11-12,.pure-u-sm-22-24{width:91.6667%}.pure-u-sm-23-24{width:95.8333%}.pure-u-sm-1,.pure-u-sm-1-1,.pure-u-sm-24-24,.pure-u-sm-5-5{width:100%}}@media screen and (min-width:48em){.pure-u-md-1,.pure-u-md-1-1,.pure-u-md-1-12,.pure-u-md-1-2,.pure-u-md-1-24,.pure-u-md-1-3,.pure-u-md-1-4,.pure-u-md-1-5,.pure-u-md-1-6,.pure-u-md-1-8,.pure-u-md-10-24,.pure-u-md-11-12,.pure-u-md-11-24,.pure-u-md-12-24,.pure-u-md-13-24,.pure-u-md-14-24,.pure-u-md-15-24,.pure-u-md-16-24,.pure-u-md-17-24,.pure-u-md-18-24,.pure-u-md-19-24,.pure-u-md-2-24,.pure-u-md-2-3,.pure-u-md-2-5,.pure-u-md-20-24,.pure-u-md-21-24,.pure-u-md-22-24,.pure-u-md-23-24,.pure-u-md-24-24,.pure-u-md-3-24,.pure-u-md-3-4,.pure-u-md-3-5,.pure-u-md-3-8,.pure-u-md-4-24,.pure-u-md-4-5,.pure-u-md-5-12,.pure-u-md-5-24,.pure-u-md-5-5,.pure-u-md-5-6,.pure-u-md-5-8,.pure-u-md-6-24,.pure-u-md-7-12,.pure-u-md-7-24,.pure-u-md-7-8,.pure-u-md-8-24,.pure-u-md-9-24{display:inline-block;letter-spacing:normal;word-spacing:normal;vertical-align:top;text-rendering:auto}.pure-u-md-1-24{width:4.1667%}.pure-u-md-1-12,.pure-u-md-2-24{width:8.3333%}.pure-u-md-1-8,.pure-u-md-3-24{width:12.5%}.pure-u-md-1-6,.pure-u-md-4-24{width:16.6667%}.pure-u-md-1-5{width:20%}.pure-u-md-5-24{width:20.8333%}.pure-u-md-1-4,.pure-u-md-6-24{width:25%}.pure-u-md-7-24{width:29.1667%}.pure-u-md-1-3,.pure-u-md-8-24{width:33.3333%}.pure-u-md-3-8,.pure-u-md-9-24{width:37.5%}.pure-u-md-2-5{width:40%}.pure-u-md-10-24,.pure-u-md-5-12{width:41.6667%}.pure-u-md-11-24{width:45.8333%}.pure-u-md-1-2,.pure-u-md-12-24{width:50%}.pure-u-md-13-24{width:54.1667%}.pure-u-md-14-24,.pure-u-md-7-12{width:58.3333%}.pure-u-md-3-5{width:60%}.pure-u-md-15-24,.pure-u-md-5-8{width:62.5%}.pure-u-md-16-24,.pure-u-md-2-3{width:66.6667%}.pure-u-md-17-24{width:70.8333%}.pure-u-md-18-24,.pure-u-md-3-4{width:75%}.pure-u-md-19-24{width:79.1667%}.pure-u-md-4-5{width:80%}.pure-u-md-20-24,.pure-u-md-5-6{width:83.3333%}.pure-u-md-21-24,.pure-u-md-7-8{width:87.5%}.pure-u-md-11-12,.pure-u-md-22-24{width:91.6667%}.pure-u-md-23-24{width:95.8333%}.pure-u-md-1,.pure-u-md-1-1,.pure-u-md-24-24,.pure-u-md-5-5{width:100%}}@media screen and (min-width:64em){.pure-u-lg-1,.pure-u-lg-1-1,.pure-u-lg-1-12,.pure-u-lg-1-2,.pure-u-lg-1-24,.pure-u-lg-1-3,.pure-u-lg-1-4,.pure-u-lg-1-5,.pure-u-lg-1-6,.pure-u-lg-1-8,.pure-u-lg-10-24,.pure-u-lg-11-12,.pure-u-lg-11-24,.pure-u-lg-12-24,.pure-u-lg-13-24,.pure-u-lg-14-24,.pure-u-lg-15-24,.pure-u-lg-16-24,.pure-u-lg-17-24,.pure-u-lg-18-24,.pure-u-lg-19-24,.pure-u-lg-2-24,.pure-u-lg-2-3,.pure-u-lg-2-5,.pure-u-lg-20-24,.pure-u-lg-21-24,.pure-u-lg-22-24,.pure-u-lg-23-24,.pure-u-lg-24-24,.pure-u-lg-3-24,.pure-u-lg-3-4,.pure-u-lg-3-5,.pure-u-lg-3-8,.pure-u-lg-4-24,.pure-u-lg-4-5,.pure-u-lg-5-12,.pure-u-lg-5-24,.pure-u-lg-5-5,.pure-u-lg-5-6,.pure-u-lg-5-8,.pure-u-lg-6-24,.pure-u-lg-7-12,.pure-u-lg-7-24,.pure-u-lg-7-8,.pure-u-lg-8-24,.pure-u-lg-9-24{display:inline-block;letter-spacing:normal;word-spacing:normal;vertical-align:top;text-rendering:auto}.pure-u-lg-1-24{width:4.1667%}.pure-u-lg-1-12,.pure-u-lg-2-24{width:8.3333%}.pure-u-lg-1-8,.pure-u-lg-3-24{width:12.5%}.pure-u-lg-1-6,.pure-u-lg-4-24{width:16.6667%}.pure-u-lg-1-5{width:20%}.pure-u-lg-5-24{width:20.8333%}.pure-u-lg-1-4,.pure-u-lg-6-24{width:25%}.pure-u-lg-7-24{width:29.1667%}.pure-u-lg-1-3,.pure-u-lg-8-24{width:33.3333%}.pure-u-lg-3-8,.pure-u-lg-9-24{width:37.5%}.pure-u-lg-2-5{width:40%}.pure-u-lg-10-24,.pure-u-lg-5-12{width:41.6667%}.pure-u-lg-11-24{width:45.8333%}.pure-u-lg-1-2,.pure-u-lg-12-24{width:50%}.pure-u-lg-13-24{width:54.1667%}.pure-u-lg-14-24,.pure-u-lg-7-12{width:58.3333%}.pure-u-lg-3-5{width:60%}.pure-u-lg-15-24,.pure-u-lg-5-8{width:62.5%}.pure-u-lg-16-24,.pure-u-lg-2-3{width:66.6667%}.pure-u-lg-17-24{width:70.8333%}.pure-u-lg-18-24,.pure-u-lg-3-4{width:75%}.pure-u-lg-19-24{width:79.1667%}.pure-u-lg-4-5{width:80%}.pure-u-lg-20-24,.pure-u-lg-5-6{width:83.3333%}.pure-u-lg-21-24,.pure-u-lg-7-8{width:87.5%}.pure-u-lg-11-12,.pure-u-lg-22-24{width:91.6667%}.pure-u-lg-23-24{width:95.8333%}.pure-u-lg-1,.pure-u-lg-1-1,.pure-u-lg-24-24,.pure-u-lg-5-5{width:100%}}@media screen and (min-width:80em){.pure-u-xl-1,.pure-u-xl-1-1,.pure-u-xl-1-12,.pure-u-xl-1-2,.pure-u-xl-1-24,.pure-u-xl-1-3,.pure-u-xl-1-4,.pure-u-xl-1-5,.pure-u-xl-1-6,.pure-u-xl-1-8,.pure-u-xl-10-24,.pure-u-xl-11-12,.pure-u-xl-11-24,.pure-u-xl-12-24,.pure-u-xl-13-24,.pure-u-xl-14-24,.pure-u-xl-15-24,.pure-u-xl-16-24,.pure-u-xl-17-24,.pure-u-xl-18-24,.pure-u-xl-19-24,.pure-u-xl-2-24,.pure-u-xl-2-3,.pure-u-xl-2-5,.pure-u-xl-20-24,.pure-u-xl-21-24,.pure-u-xl-22-24,.pure-u-xl-23-24,.pure-u-xl-24-24,.pure-u-xl-3-24,.pure-u-xl-3-4,.pure-u-xl-3-5,.pure-u-xl-3-8,.pure-u-xl-4-24,.pure-u-xl-4-5,.pure-u-xl-5-12,.pure-u-xl-5-24,.pure-u-xl-5-5,.pure-u-xl-5-6,.pure-u-xl-5-8,.pure-u-xl-6-24,.pure-u-xl-7-12,.pure-u-xl-7-24,.pure-u-xl-7-8,.pure-u-xl-8-24,.pure-u-xl-9-24{display:inline-block;letter-spacing:normal;word-spacing:normal;vertical-align:top;text-rendering:auto}.pure-u-xl-1-24{width:4.1667%}.pure-u-xl-1-12,.pure-u-xl-2-24{width:8.3333%}.pure-u-xl-1-8,.pure-u-xl-3-24{width:12.5%}.pure-u-xl-1-6,.pure-u-xl-4-24{width:16.6667%}.pure-u-xl-1-5{width:20%}.pure-u-xl-5-24{width:20.8333%}.pure-u-xl-1-4,.pure-u-xl-6-24{width:25%}.pure-u-xl-7-24{width:29.1667%}.pure-u-xl-1-3,.pure-u-xl-8-24{width:33.3333%}.pure-u-xl-3-8,.pure-u-xl-9-24{width:37.5%}.pure-u-xl-2-5{width:40%}.pure-u-xl-10-24,.pure-u-xl-5-12{width:41.6667%}.pure-u-xl-11-24{width:45.8333%}.pure-u-xl-1-2,.pure-u-xl-12-24{width:50%}.pure-u-xl-13-24{width:54.1667%}.pure-u-xl-14-24,.pure-u-xl-7-12{width:58.3333%}.pure-u-xl-3-5{width:60%}.pure-u-xl-15-24,.pure-u-xl-5-8{width:62.5%}.pure-u-xl-16-24,.pure-u-xl-2-3{width:66.6667%}.pure-u-xl-17-24{width:70.8333%}.pure-u-xl-18-24,.pure-u-xl-3-4{width:75%}.pure-u-xl-19-24{width:79.1667%}.pure-u-xl-4-5{width:80%}.pure-u-xl-20-24,.pure-u-xl-5-6{width:83.3333%}.pure-u-xl-21-24,.pure-u-xl-7-8{width:87.5%}.pure-u-xl-11-12,.pure-u-xl-22-24{width:91.6667%}.pure-u-xl-23-24{width:95.8333%}.pure-u-xl-1,.pure-u-xl-1-1,.pure-u-xl-24-24,.pure-u-xl-5-5{width:100%}}
)"";

/**************************************************************************/
const char script_js[] PROGMEM = R""(
  var blocked = false;

  /*
   * Handle dynamic updates, such as slider dragging
   */
  function update ()  
  {
    /*
     * Setup request, including a callback that runs any
     * subsequent requests on completion
     */
    document.getElementById("autoBrightnessHidden").disabled = document.getElementById("autoBrightness").checked;
    document.getElementById("useSequenceHidden").disabled = document.getElementById("useSequence").checked;
    
    var form = new FormData (document.getElementById ("form"));
    var request = new XMLHttpRequest ();
    request.open ("POST", "/update", true);
    request.addEventListener ("load", event => blocked = false);

    /*
     * Run if we can
     */
    if (!blocked)
    {
      request.send (form);
      blocked = true;
    }
  }

  /*
   * Handle full update, such as selecting from a list
   */
  function change ()  
  {
    document.getElementById("autoBrightnessHidden").disabled = document.getElementById("autoBrightness").checked;
    document.getElementById("useSequenceHidden").disabled = document.getElementById("useSequence").checked;
    
    var form = document.getElementById ("form");
    var request = new XMLHttpRequest ();
    request.open ("POST", "/change", true);
    request.send (new FormData (form));
  }

  function save (file = '')  
  {
    var request = new XMLHttpRequest ();
    request.open ("POST", "/save?file="+file, true);
    request.send ('');
  }

  function updateSingle (el)
  {
    if(el.type=='checkbox') {
       if(!el.checked) {
          el = document.getElementById(el.id+"Hidden");
       }
    }

    // change ->send and save, update -> only send
    var request = new XMLHttpRequest ();
    request.open ("POST", "/update", false);
    var formdata = new FormData ();
    formdata.append (el.name, el.value);
    request.send (formdata);
    //location.reload (true);
    return false;
  }

  /*
   * Display a message ticker
   */
  function show (el)
  {
    var request = new XMLHttpRequest ();
    request.open ("POST", "/show", false);
    var formdata = new FormData ();
    formdata.append (el.name, el.value);
    request.send (formdata);
    return false;
  }

  /*
   * Fill the timezone selector - has to be done dynamically
   * due to memory constraints
   */
  function populate_timezones (page)
  {
    var request = new XMLHttpRequest ();
    request.onreadystatechange = function() 
    {
      if (this.readyState == 4 && this.status == 200) 
      {
        var select = document.getElementById ("timezone");
        function add_selector (item)
        {
          node = document.createElement ("OPTION");
          if (item == timezone)
          {
            node.selected = true;
          }
          node.label = item;
          node.textContent = item;
          select.appendChild (node);
        }

        var timezones = JSON.parse (this.responseText);
        if(timezones.length==0)
          return;

        timezones.forEach (add_selector);

        populate_timezones(page+1);
      }
    };

    request.open ("GET", "/timezones?p="+page, true);
    request.send ();
  }

  /*
   * Load one of the cheesy presets
   */
  function load_preset ()
  {
    var request = new XMLHttpRequest ();
    var select = document.getElementById ("preset");
    request.open ("POST", "/load_preset", false);
    var formdata = new FormData ();
    formdata.append ("preset", select.options[select.selectedIndex].text);
    request.send (formdata);
    location.reload (true);
    return false;
  }

/*  var connection = new WebSocket('ws://' + location.hostname + ':81/', ['arduino']);
connection.onopen = function () {
  connection.send('Connect ' + new Date());
};
connection.onerror = function (error) {
  console.log('WebSocket Error ', error);
};
connection.onmessage = function (e) {
  console.log('Server: ', e.data);
};
connection.onclose = function () {
  console.log('WebSocket connection closed');
};*/

  function hasClass(ele,cls) {
    return !!ele.className.match(new RegExp('(\\s|^)'+cls+'(\\s|$)'));
  }

  function addClass(ele,cls) {
    if (!hasClass(ele,cls)) ele.className += " "+cls;
  }

  function removeClass(ele,cls) {
    if (hasClass(ele,cls)) {
      var reg = new RegExp('(\\s|^)'+cls+'(\\s|$)');
      ele.className=ele.className.replace(reg,' ');
    }
  }

function toggleNetwork(id) {
    var net = document.getElementById(id);
    var hidden = hasClass(net, "hide");
    if(hidden) removeClass(net, "hide"); else addClass(net, "hide");
  }

function load_content() {
  (() => {
        const includes = document.getElementsByTagName('include');
        [].forEach.call(includes, i => {
            let filePath = i.getAttribute('src');
            fetch(filePath).then(file => {
                file.text().then(content => {
                    i.insertAdjacentHTML('afterend', content);
                    i.remove();
                });
            });
        });
    })();
}

function init() {
   populate_timezones(0);
   load_content();
}
)"";

/**************************************************************************/

const char page_template[] PROGMEM = R""(<!DOCTYPE html>
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
  <body onload="init()" style="padding:0.8em; font-family: 'Montserrat', sans-serif;">
  
    <h1><center>MqClock</center></h1>
    
    <div class="pure-g">
      <div class="pure-u-1 pure-u-md-1-3"> 
        <include src="/part?p=conn">Loading...</include>
      </div>
      <div class="pure-u-1 pure-u-md-1-3"> 
        <form class="pure-form pure-form-aligned"
        <fieldset>
            <legend>Weather <a href="#" onClick="toggleNetwork('showWeather')" class="pure-button small">show/hide</a></legend>
            <div  id="showWeather" class="hide">
              <div class="pure-control-group">
                <label for="timezone">Timezone</label>
                <select id="timezone" name="timezone" onChange="updateSingle(this)"></select>
              </div>  
              <include src="/part?p=weather">Loading...</include>
            </div>
        </fieldset>
        </form>
      </div>
      <div class="pure-u-1 pure-u-md-1-3">
      <form>
      <legend>
        <a href="/mqtt">MQTT sensors/sequence/icons</a>
      </legend>
      </form>
      </div>
    </div>
    <form class="pure-form pure-form-aligned" onSubmit="event.preventDefault();">

    <div class="pure-g">
      <div class="pure-u-1 pure-u-md-1-2"> 
        <include src="/part?p=master">Loading...</include>
      </div>
      <div class="pure-u-1 pure-u-md-1-2"> 
        <include src="/part?p=effects">Loading...</include>
      </div>
    </div>
    <div class="pure-g">
      <div class="pure-u-1 pure-u-md-1-2">    
      <fieldset>
          <legend>Primary display</legend>
      
          <div class="pure-control-group">
            <label for="pFmt">Format</label>
            <input type="text" title="H = hours (24-hour clock)
h = hours (12-hour clock)
M = minutes
Y = year (4-digit)
y = year (2-digit)
m = month
d = day of month
S = seconds
p = ping time (ms)
C = Temperature in Celsius
F = Temperature in Fahrenheit
X = display defined 'Text'
x - display Char ex. xW
b - binary numeric value ex. bHbMbS
v[1-6] - mqtt sensor
V[1-6] - as v1 with format ex. V2%4.1f
s[1-6] - pattern for On/Off
T - internal DS sensor
L - internal lighting sensor
i[0-25] - display icon
! = flash ex. !:
: . * - and space" name="pFmt" value="{{pFmt}}" onChange="updateSingle(this)">
          </div>

          <div class="pure-control-group">
            <label for="pFt">Font</label>
            <select name="pFt" onChange="updateSingle(this)">{{primary_font_choices}}</select>
          </div>

          <div class="pure-control-group">
            <label for="pC">Color</label>
            <select name="pCM" onInput="updateSingle(this)" onChange="updateSingle(this)">{{primary_color_mode_choices}}</select>
            <input type="color" class="pure-button" style="height:2em; padding:0.2em;" name="pC" value="{{pC}}" onChange="updateSingle(this)">
          </div>
      
          <div class="pure-control-group">
            <label for="pX">X offset</label>
            <input type="range" name="pX" value="{{pX}}" onInput="updateSingle(this)" onChange="updateSingle(this)" min="-{{PanelWidth}}" max="{{PanelWidth}}" class="slider">
          </div>
      
          <div class="pure-control-group">
            <label for="pY">Y offset</label>
            <input type="range" name="pY" value="{{pY}}" onInput="updateSingle(this)" onChange="updateSingle(this)" min="-{{PanelHeight}}" max="{{PanelHeight}}" class="slider">
          </div>
          <div class="pure-control-group">
            <label for="pT">Text</label>
            <input type="text" name="pT" value="{{pT}}" onInput="updateSingle(this)" onChange="updateSingle(this)">
          </div>
      </fieldset>      
      </div>
      <div class="pure-u-1 pure-u-md-1-2"> 
      <fieldset>
          <legend>Secondary display</legend>
      
          <div class="pure-control-group">
            <label for="sFmt">Format</label>
            <input type="text" name="sFmt" value="{{sFmt}}" onChange="updateSingle(this)">
          </div>

          <div class="pure-control-group">
            <label for="sFt">Font</label>
            <select name="sFt" onChange="updateSingle(this)">{{secondary_font_choices}}</select>
          </div>

          <div class="pure-control-group">
            <label for="sC">Color</label>
            <select name="sCM" onInput="updateSingle(this)" onChange="updateSingle(this)">{{secondary_color_mode_choices}}</select>
            <input type="color" class="pure-button" style="height:2em; padding:0.2em;" name="sC" value="{{sC}}" onChange="updateSingle(this)">
          </div>
      
          <div class="pure-control-group">
            <label for="sX">X offset</label>
            <input type="range" name="sX" value="{{sX}}" onInput="updateSingle(this)" onChange="updateSingle(this)" min="-{{PanelWidth}}" max="{{PanelWidth}}" class="slider">
          </div>
      
          <div class="pure-control-group">
            <label for="sY">Y offset</label>
            <input type="range" name="sY" value="{{sY}}" onInput="updateSingle(this)" onChange="updateSingle(this)" min="-{{PanelHeight}}" max="{{PanelHeight}}" class="slider">
          </div>
          <div class="pure-control-group">
            <label for="sT">Text</label>
            <input type="text" name="sT" value="{{sT}}" onInput="updateSingle(this)" onChange="updateSingle(this)">
          </div>
      </fieldset>      
      </div>
      </div>
          
      <include src="/part?p=message">Loading...</include>
      
      <a class="pure-button" style="background: rgb(255, 120, 30);" onClick="save();">Save</a>
      <a class="pure-button" style="background: rgb(255, 120, 30);" onClick="save('User1');">As User1</a>
      <a class="pure-button" style="background: rgb(255, 120, 30);" onClick="save('User2');">As User2</a>
    </form>
  </body>
</html>
)""

/**************************************************************************/
;

const char page_template_connection[] PROGMEM = R""(
  <form id="form" class="pure-form pure-form-aligned">
      <fieldset>
          <legend>Network <a href="#" onClick="toggleNetwork('showNetwork')" class="pure-button small">show/hide</a></legend>
          <div  id="showNetwork" class="{{hide_net}}">
            <div class="pure-control-group">
              <label for="ssid">SSID</label>
              <input type="text" name="ssid" value="{{ssid}}" onChange="change()">
            </div>
                    
            <div class="pure-control-group">
              <label for="password">Password</label>
              <input type="password" name="password" value="{{password}}" onChange="change()">
            </div>

            <div class="pure-control-group">
              <label for="pingTarget">MQTT server</label>
              <input type="text" id="mqttHost" name="mqttHost" value="{{mqttHost}}" placeholder="e.g. 192.168.1.22" onChange="change()">
            </div>
            <div class="pure-control-group">
              <label>&nbsp;</label>
              <a class="pure-button" style="background: rgb(255, 120, 30);" href="/reboot"><b>Reboot</b></a>
            </div>
          </div>
      </fieldset>
  </form>
)"";

const char page_template_weather[] PROGMEM = R""(

          <div class="pure-control-group">
            <label for="weatherLocation">Weather location</label>
            <input type="text" id="weatherLocation" name="weatherLocation" value="{{weatherLocation}}" placeholder="e.g. London,UK" onChange="updateSingle(this)">
          </div>
          
          <div class="pure-control-group">
            <label for="OWMAPIKey"><a href="https://openweathermap.org/">OWM</a> API Key</label>
            <input type="text" name="OWMAPIKey" value="{{OWMAPIKey}}" onChange="updateSingle(this)">
          </div>

          <div class="pure-control-group">
            <label for="pingTarget">Ping target</label>
            <input type="text" id="pingTarget" name="pingTarget" value="{{pingTarget}}" placeholder="e.g. 8.8.8.8" onChange="updateSingle(this)">
          </div>
)"";

const char page_template_master[] PROGMEM = R""(
      <fieldset>
          <legend>Master controls</legend>
                
          <div class="pure-control-group">
            <label for="masterBrightness">Brightness</label>
            <input type="range" name="masterBrightness" value="{{masterBrightness}}" onInput="updateSingle(this)" onChange="updateSingle(this)" min="1" max="255" class="slider" style="width: 20em;"/>
          </div>
          <div class="pure-control-group">
            <label for="autoBrightness">Auto Brightness</label>
            <input id="autoBrightness" type="checkbox" name="autoBrightness" {{autoBrightness}} onChange="updateSingle(this)" value="checked"/>
            <input id="autoBrightnessHidden" type="hidden" value="unchecked" name="autoBrightness"/>
          </div>
          
          <div class="pure-control-group">
            <label for="preset">Preset</label>
            <select id="preset" name="preset" onChange="return load_preset();">{{preset_choices}}</select>
          </div>
          
          <div class="pure-control-group">
            <label for="useSequence">Use sequence</label>
            <input id="useSequence" type="checkbox" name="useSequence" {{checked-useSequence}} onChange="updateSingle(this)" value="1"/>
            <input id="useSequenceHidden" type="hidden" value="0" name="useSequence"/>
          </div>
          <div class="pure-control-group">
            <label for="useAnime">Use animations</label>
            <input id="useAnime" type="checkbox" name="useAnime" {{checked-useAnime}} onChange="updateSingle(this)" value="1"/>
            <input id="useAnimeHidden" type="hidden" value="0" name="useAnime"/>
          </div>
      </fieldset>
)"";

const char page_template_message[] PROGMEM = R""(
  <fieldset>
          <legend>Message</legend>
          
          <div class="pure-control-group">
            <label for="message">Text</label>
            <input type="text" id="message" name="message" value="{{message}}" placeholder="Enter your message" onInput="updateSingle(this)" />
            <button type="none" class="pure-button pure-button-primary" onclick="show(document.getElementById ('message'))">Send</button>
          </div>
          
          <div class="pure-control-group">
            <label for="messageColor">Color</label>
            <input type="color" class="pure-button" style="height:2em; padding:0.2em;" name="messageColor" value="{{messageColor}}" onInput="updateSingle(this)" onChange="updateSingle(this)"/>
          </div>
          
          <div class="pure-control-group">
            <label for="messageRepeat">Repeat</label>
            <input type="text" id="messageRepeat" name="messageRepeat" placeholder="Repeat interval in seconds" onInput="updateSingle(this)" onChange="updateSingle(this)" value="{{messageRepeat}}"/>
          </div>
          
      </fieldset>  
)"";

const char page_template_effects[] PROGMEM = R""(
  <fieldset>
          <legend>Background effect</legend>
      
          <div class="pure-control-group">
            <label for="effect">Mode</label>
            <select name="effect" onChange="updateSingle(this)">{{effect_choices}}</select>
          </div>

          <div class="pure-control-group">
            <label for="effectColorMode">Color</label>
            <select name="effectColorMode" onChange="updateSingle(this)">{{effect_color_mode_choices}}</select>
            <input type="color" class="pure-button" style="height:2em; padding:0.2em;" name="effectColor" value="{{effectColor}}" onInput="updateSingle(this)" onChange="updateSingle(this)">
          </div>
          
          <div class="pure-control-group">
            <label for="effectSpeed">Speed</label>
            <input type="range" name="effectSpeed" value="{{effectSpeed}}" onInput="updateSingle(this)" onChange="updateSingle(this)" min="0" max="500" class="slider">
          </div>      
          
          <div class="pure-control-group">
            <label for="effectDecay">Decay</label>
            <input type="range" name="effectDecay" value="{{effectDecay}}" onInput="updateSingle(this)" onChange="updateSingle(this)" min="0" max="200" class="slider">
          </div>                
      </fieldset>
)"";
