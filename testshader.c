<?xml version="1.0" encoding="UTF-8"?>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Strict//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd">
<html xmlns="http://www.w3.org/1999/xhtml" xml:lang="en-US" lang="en-US">
<head>
<link rel="icon" href="/SDL/static/hgicon.png" type="image/png" />
<meta name="robots" content="index, nofollow"/>
<link rel="stylesheet" href="/SDL/static/style-gitweb.css" type="text/css" />
<script type="text/javascript" src="/SDL/static/mercurial.js"></script>

<title>SDL: test/testshader.c@b8d8f9674717</title>
<link rel="alternate" type="application/atom+xml"
   href="/SDL/atom-log" title="Atom feed for SDL"/>
<link rel="alternate" type="application/rss+xml"
   href="/SDL/rss-log" title="RSS feed for SDL"/>
</head>
<body>

<div class="page_header">
<a href="http://mercurial.selenic.com/" title="Mercurial" style="float: right;">Mercurial</a>
<a href="/">Mercurial</a> &gt; <a href="/SDL">SDL</a>  / file revision
</div>

<div class="page_nav">
<a href="/SDL/summary">summary</a> |
<a href="/SDL/shortlog">shortlog</a> |
<a href="/SDL/log">changelog</a> |
<a href="/SDL/graph">graph</a> |
<a href="/SDL/tags">tags</a> |
<a href="/SDL/bookmarks">bookmarks</a> |
<a href="/SDL/branches">branches</a> |
<a href="/SDL/file/b8d8f9674717/test/">files</a> |
<a href="/SDL/rev/b8d8f9674717">changeset</a> |
file |
<a href="/SDL/file/tip/test/testshader.c">latest</a> |
<a href="/SDL/log/b8d8f9674717/test/testshader.c">revisions</a> |
<a href="/SDL/annotate/b8d8f9674717/test/testshader.c">annotate</a> |
<a href="/SDL/diff/b8d8f9674717/test/testshader.c">diff</a> |
<a href="/SDL/comparison/b8d8f9674717/test/testshader.c">comparison</a> |
<a href="/SDL/raw-file/b8d8f9674717/test/testshader.c">raw</a> |
<a href="/SDL/help">help</a>
<br/>
</div>

<div class="title">test/testshader.c</div>

<div class="title_text">
<table cellspacing="0">
<tr>
 <td>author</td>
 <td>&#65;&#108;&#101;&#120;&#32;&#83;&#122;&#112;&#97;&#107;&#111;&#119;&#115;&#107;&#105;&#32;&#60;&#115;&#108;&#105;&#109;&#101;&#55;&#51;&#64;&#103;&#109;&#97;&#105;&#108;&#46;&#99;&#111;&#109;&#62;</td></tr>
<tr>
 <td></td>
 <td class="date age">Sat, 16 May 2015 17:35:36 -0300</td></tr>

<tr>
 <td>changeset 9604</td>
 <td style="font-family:monospace"><a class="list" href="/SDL/rev/b8d8f9674717">b8d8f9674717</a></td></tr>

<tr>
<td>parent 7996</td>
<td style="font-family:monospace">
<a class="list" href="/SDL/file/be1526907541/test/testshader.c">
be1526907541
</a>
</td>
</tr>

<tr>
 <td>permissions</td>
 <td style="font-family:monospace">-rw-r--r--</td></tr>
</table>
</div>

<div class="page_path">
Code style cleanup in the GLES and GLES2 render backends.
</div>

<div class="page_body">

<div style="font-family:monospace" class="parity0">
<pre><a class="linenr" href="#l1" id="l1">     1</a> /*
</pre>
</div>
<div style="font-family:monospace" class="parity1">
<pre><a class="linenr" href="#l2" id="l2">     2</a>   Copyright (C) 1997-2014 Sam Lantinga &lt;slouken@libsdl.org&gt;
</pre>
</div>
<div style="font-family:monospace" class="parity0">
<pre><a class="linenr" href="#l3" id="l3">     3</a> 
</pre>
</div>
<div style="font-family:monospace" class="parity1">
<pre><a class="linenr" href="#l4" id="l4">     4</a>   This software is provided 'as-is', without any express or implied
</pre>
</div>
<div style="font-family:monospace" class="parity0">
<pre><a class="linenr" href="#l5" id="l5">     5</a>   warranty.  In no event will the authors be held liable for any damages
</pre>
</div>
<div style="font-family:monospace" class="parity1">
<pre><a class="linenr" href="#l6" id="l6">     6</a>   arising from the use of this software.
</pre>
</div>
<div style="font-family:monospace" class="parity0">
<pre><a class="linenr" href="#l7" id="l7">     7</a> 
</pre>
</div>
<div style="font-family:monospace" class="parity1">
<pre><a class="linenr" href="#l8" id="l8">     8</a>   Permission is granted to anyone to use this software for any purpose,
</pre>
</div>
<div style="font-family:monospace" class="parity0">
<pre><a class="linenr" href="#l9" id="l9">     9</a>   including commercial applications, and to alter it and redistribute it
</pre>
</div>
<div style="font-family:monospace" class="parity1">
<pre><a class="linenr" href="#l10" id="l10">    10</a>   freely.
</pre>
</div>
<div style="font-family:monospace" class="parity0">
<pre><a class="linenr" href="#l11" id="l11">    11</a> */
</pre>
</div>
<div style="font-family:monospace" class="parity1">
<pre><a class="linenr" href="#l12" id="l12">    12</a> /* This is a simple example of using GLSL shaders with SDL */
</pre>
</div>
<div style="font-family:monospace" class="parity0">
<pre><a class="linenr" href="#l13" id="l13">    13</a> 
</pre>
</div>
<div style="font-family:monospace" class="parity1">
<pre><a class="linenr" href="#l14" id="l14">    14</a> #include &quot;SDL.h&quot;
</pre>
</div>
<div style="font-family:monospace" class="parity0">
<pre><a class="linenr" href="#l15" id="l15">    15</a> 
</pre>
</div>
<div style="font-family:monospace" class="parity1">
<pre><a class="linenr" href="#l16" id="l16">    16</a> #ifdef HAVE_OPENGL
</pre>
</div>
<div style="font-family:monospace" class="parity0">
<pre><a class="linenr" href="#l17" id="l17">    17</a> 
</pre>
</div>
<div style="font-family:monospace" class="parity1">
<pre><a class="linenr" href="#l18" id="l18">    18</a> #include &quot;SDL_opengl.h&quot;
</pre>
</div>
<div style="font-family:monospace" class="parity0">
<pre><a class="linenr" href="#l19" id="l19">    19</a> 
</pre>
</div>
<div style="font-family:monospace" class="parity1">
<pre><a class="linenr" href="#l20" id="l20">    20</a> 
</pre>
</div>
<div style="font-family:monospace" class="parity0">
<pre><a class="linenr" href="#l21" id="l21">    21</a> static SDL_bool shaders_supported;
</pre>
</div>
<div style="font-family:monospace" class="parity1">
<pre><a class="linenr" href="#l22" id="l22">    22</a> static int      current_shader = 0;
</pre>
</div>
<div style="font-family:monospace" class="parity0">
<pre><a class="linenr" href="#l23" id="l23">    23</a> 
</pre>
</div>
<div style="font-family:monospace" class="parity1">
<pre><a class="linenr" href="#l24" id="l24">    24</a> enum {
</pre>
</div>
<div style="font-family:monospace" class="parity0">
<pre><a class="linenr" href="#l25" id="l25">    25</a>     SHADER_COLOR,
</pre>
</div>
<div style="font-family:monospace" class="parity1">
<pre><a class="linenr" href="#l26" id="l26">    26</a>     SHADER_TEXTURE,
</pre>
</div>
<div style="font-family:monospace" class="parity0">
<pre><a class="linenr" href="#l27" id="l27">    27</a>     SHADER_TEXCOORDS,
</pre>
</div>
<div style="font-family:monospace" class="parity1">
<pre><a class="linenr" href="#l28" id="l28">    28</a>     NUM_SHADERS
</pre>
</div>
<div style="font-family:monospace" class="parity0">
<pre><a class="linenr" href="#l29" id="l29">    29</a> };
</pre>
</div>
<div style="font-family:monospace" class="parity1">
<pre><a class="linenr" href="#l30" id="l30">    30</a> 
</pre>
</div>
<div style="font-family:monospace" class="parity0">
<pre><a class="linenr" href="#l31" id="l31">    31</a> typedef struct {
</pre>
</div>
<div style="font-family:monospace" class="parity1">
<pre><a class="linenr" href="#l32" id="l32">    32</a>     GLhandleARB program;
</pre>
</div>
<div style="font-family:monospace" class="parity0">
<pre><a class="linenr" href="#l33" id="l33">    33</a>     GLhandleARB vert_shader;
</pre>
</div>
<div style="font-family:monospace" class="parity1">
<pre><a class="linenr" href="#l34" id="l34">    34</a>     GLhandleARB frag_shader;
</pre>
</div>
<div style="font-family:monospace" class="parity0">
<pre><a class="linenr" href="#l35" id="l35">    35</a>     const char *vert_source;
</pre>
</div>
<div style="font-family:monospace" class="parity1">
<pre><a class="linenr" href="#l36" id="l36">    36</a>     const char *frag_source;
</pre>
</div>
<div style="font-family:monospace" class="parity0">
<pre><a class="linenr" href="#l37" id="l37">    37</a> } ShaderData;
</pre>
</div>
<div style="font-family:monospace" class="parity1">
<pre><a class="linenr" href="#l38" id="l38">    38</a> 
</pre>
</div>
<div style="font-family:monospace" class="parity0">
<pre><a class="linenr" href="#l39" id="l39">    39</a> static ShaderData shaders[NUM_SHADERS] = {
</pre>
</div>
<div style="font-family:monospace" class="parity1">
<pre><a class="linenr" href="#l40" id="l40">    40</a> 
</pre>
</div>
<div style="font-family:monospace" class="parity0">
<pre><a class="linenr" href="#l41" id="l41">    41</a>     /* SHADER_COLOR */
</pre>
</div>
<div style="font-family:monospace" class="parity1">
<pre><a class="linenr" href="#l42" id="l42">    42</a>     { 0, 0, 0,
</pre>
</div>
<div style="font-family:monospace" class="parity0">
<pre><a class="linenr" href="#l43" id="l43">    43</a>         /* vertex shader */
</pre>
</div>
<div style="font-family:monospace" class="parity1">
<pre><a class="linenr" href="#l44" id="l44">    44</a> &quot;varying vec4 v_color;\n&quot;
</pre>
</div>
<div style="font-family:monospace" class="parity0">
<pre><a class="linenr" href="#l45" id="l45">    45</a> &quot;\n&quot;
</pre>
</div>
<div style="font-family:monospace" class="parity1">
<pre><a class="linenr" href="#l46" id="l46">    46</a> &quot;void main()\n&quot;
</pre>
</div>
<div style="font-family:monospace" class="parity0">
<pre><a class="linenr" href="#l47" id="l47">    47</a> &quot;{\n&quot;
</pre>
</div>
<div style="font-family:monospace" class="parity1">
<pre><a class="linenr" href="#l48" id="l48">    48</a> &quot;    gl_Position = gl_ModelViewProjectionMatrix * gl_Vertex;\n&quot;
</pre>
</div>
<div style="font-family:monospace" class="parity0">
<pre><a class="linenr" href="#l49" id="l49">    49</a> &quot;    v_color = gl_Color;\n&quot;
</pre>
</div>
<div style="font-family:monospace" class="parity1">
<pre><a class="linenr" href="#l50" id="l50">    50</a> &quot;}&quot;,
</pre>
</div>
<div style="font-family:monospace" class="parity0">
<pre><a class="linenr" href="#l51" id="l51">    51</a>         /* fragment shader */
</pre>
</div>
<div style="font-family:monospace" class="parity1">
<pre><a class="linenr" href="#l52" id="l52">    52</a> &quot;varying vec4 v_color;\n&quot;
</pre>
</div>
<div style="font-family:monospace" class="parity0">
<pre><a class="linenr" href="#l53" id="l53">    53</a> &quot;\n&quot;
</pre>
</div>
<div style="font-family:monospace" class="parity1">
<pre><a class="linenr" href="#l54" id="l54">    54</a> &quot;void main()\n&quot;
</pre>
</div>
<div style="font-family:monospace" class="parity0">
<pre><a class="linenr" href="#l55" id="l55">    55</a> &quot;{\n&quot;
</pre>
</div>
<div style="font-family:monospace" class="parity1">
<pre><a class="linenr" href="#l56" id="l56">    56</a> &quot;    gl_FragColor = v_color;\n&quot;
</pre>
</div>
<div style="font-family:monospace" class="parity0">
<pre><a class="linenr" href="#l57" id="l57">    57</a> &quot;}&quot;
</pre>
</div>
<div style="font-family:monospace" class="parity1">
<pre><a class="linenr" href="#l58" id="l58">    58</a>     },
</pre>
</div>
<div style="font-family:monospace" class="parity0">
<pre><a class="linenr" href="#l59" id="l59">    59</a> 
</pre>
</div>
<div style="font-family:monospace" class="parity1">
<pre><a class="linenr" href="#l60" id="l60">    60</a>     /* SHADER_TEXTURE */
</pre>
</div>
<div style="font-family:monospace" class="parity0">
<pre><a class="linenr" href="#l61" id="l61">    61</a>     { 0, 0, 0,
</pre>
</div>
<div style="font-family:monospace" class="parity1">
<pre><a class="linenr" href="#l62" id="l62">    62</a>         /* vertex shader */
</pre>
</div>
<div style="font-family:monospace" class="parity0">
<pre><a class="linenr" href="#l63" id="l63">    63</a> &quot;varying vec4 v_color;\n&quot;
</pre>
</div>
<div style="font-family:monospace" class="parity1">
<pre><a class="linenr" href="#l64" id="l64">    64</a> &quot;varying vec2 v_texCoord;\n&quot;
</pre>
</div>
<div style="font-family:monospace" class="parity0">
<pre><a class="linenr" href="#l65" id="l65">    65</a> &quot;\n&quot;
</pre>
</div>
<div style="font-family:monospace" class="parity1">
<pre><a class="linenr" href="#l66" id="l66">    66</a> &quot;void main()\n&quot;
</pre>
</div>
<div style="font-family:monospace" class="parity0">
<pre><a class="linenr" href="#l67" id="l67">    67</a> &quot;{\n&quot;
</pre>
</div>
<div style="font-family:monospace" class="parity1">
<pre><a class="linenr" href="#l68" id="l68">    68</a> &quot;    gl_Position = gl_ModelViewProjectionMatrix * gl_Vertex;\n&quot;
</pre>
</div>
<div style="font-family:monospace" class="parity0">
<pre><a class="linenr" href="#l69" id="l69">    69</a> &quot;    v_color = gl_Color;\n&quot;
</pre>
</div>
<div style="font-family:monospace" class="parity1">
<pre><a class="linenr" href="#l70" id="l70">    70</a> &quot;    v_texCoord = vec2(gl_MultiTexCoord0);\n&quot;
</pre>
</div>
<div style="font-family:monospace" class="parity0">
<pre><a class="linenr" href="#l71" id="l71">    71</a> &quot;}&quot;,
</pre>
</div>
<div style="font-family:monospace" class="parity1">
<pre><a class="linenr" href="#l72" id="l72">    72</a>         /* fragment shader */
</pre>
</div>
<div style="font-family:monospace" class="parity0">
<pre><a class="linenr" href="#l73" id="l73">    73</a> &quot;varying vec4 v_color;\n&quot;
</pre>
</div>
<div style="font-family:monospace" class="parity1">
<pre><a class="linenr" href="#l74" id="l74">    74</a> &quot;varying vec2 v_texCoord;\n&quot;
</pre>
</div>
<div style="font-family:monospace" class="parity0">
<pre><a class="linenr" href="#l75" id="l75">    75</a> &quot;uniform sampler2D tex0;\n&quot;
</pre>
</div>
<div style="font-family:monospace" class="parity1">
<pre><a class="linenr" href="#l76" id="l76">    76</a> &quot;\n&quot;
</pre>
</div>
<div style="font-family:monospace" class="parity0">
<pre><a class="linenr" href="#l77" id="l77">    77</a> &quot;void main()\n&quot;
</pre>
</div>
<div style="font-family:monospace" class="parity1">
<pre><a class="linenr" href="#l78" id="l78">    78</a> &quot;{\n&quot;
</pre>
</div>
<div style="font-family:monospace" class="parity0">
<pre><a class="linenr" href="#l79" id="l79">    79</a> &quot;    gl_FragColor = texture2D(tex0, v_texCoord) * v_color;\n&quot;
</pre>
</div>
<div style="font-family:monospace" class="parity1">
<pre><a class="linenr" href="#l80" id="l80">    80</a> &quot;}&quot;
</pre>
</div>
<div style="font-family:monospace" class="parity0">
<pre><a class="linenr" href="#l81" id="l81">    81</a>     },
</pre>
</div>
<div style="font-family:monospace" class="parity1">
<pre><a class="linenr" href="#l82" id="l82">    82</a> 
</pre>
</div>
<div style="font-family:monospace" class="parity0">
<pre><a class="linenr" href="#l83" id="l83">    83</a>     /* SHADER_TEXCOORDS */
</pre>
</div>
<div style="font-family:monospace" class="parity1">
<pre><a class="linenr" href="#l84" id="l84">    84</a>     { 0, 0, 0,
</pre>
</div>
<div style="font-family:monospace" class="parity0">
<pre><a class="linenr" href="#l85" id="l85">    85</a>         /* vertex shader */
</pre>
</div>
<div style="font-family:monospace" class="parity1">
<pre><a class="linenr" href="#l86" id="l86">    86</a> &quot;varying vec2 v_texCoord;\n&quot;
</pre>
</div>
<div style="font-family:monospace" class="parity0">
<pre><a class="linenr" href="#l87" id="l87">    87</a> &quot;\n&quot;
</pre>
</div>
<div style="font-family:monospace" class="parity1">
<pre><a class="linenr" href="#l88" id="l88">    88</a> &quot;void main()\n&quot;
</pre>
</div>
<div style="font-family:monospace" class="parity0">
<pre><a class="linenr" href="#l89" id="l89">    89</a> &quot;{\n&quot;
</pre>
</div>
<div style="font-family:monospace" class="parity1">
<pre><a class="linenr" href="#l90" id="l90">    90</a> &quot;    gl_Position = gl_ModelViewProjectionMatrix * gl_Vertex;\n&quot;
</pre>
</div>
<div style="font-family:monospace" class="parity0">
<pre><a class="linenr" href="#l91" id="l91">    91</a> &quot;    v_texCoord = vec2(gl_MultiTexCoord0);\n&quot;
</pre>
</div>
<div style="font-family:monospace" class="parity1">
<pre><a class="linenr" href="#l92" id="l92">    92</a> &quot;}&quot;,
</pre>
</div>
<div style="font-family:monospace" class="parity0">
<pre><a class="linenr" href="#l93" id="l93">    93</a>         /* fragment shader */
</pre>
</div>
<div style="font-family:monospace" class="parity1">
<pre><a class="linenr" href="#l94" id="l94">    94</a> &quot;varying vec2 v_texCoord;\n&quot;
</pre>
</div>
<div style="font-family:monospace" class="parity0">
<pre><a class="linenr" href="#l95" id="l95">    95</a> &quot;\n&quot;
</pre>
</div>
<div style="font-family:monospace" class="parity1">
<pre><a class="linenr" href="#l96" id="l96">    96</a> &quot;void main()\n&quot;
</pre>
</div>
<div style="font-family:monospace" class="parity0">
<pre><a class="linenr" href="#l97" id="l97">    97</a> &quot;{\n&quot;
</pre>
</div>
<div style="font-family:monospace" class="parity1">
<pre><a class="linenr" href="#l98" id="l98">    98</a> &quot;    vec4 color;\n&quot;
</pre>
</div>
<div style="font-family:monospace" class="parity0">
<pre><a class="linenr" href="#l99" id="l99">    99</a> &quot;    vec2 delta;\n&quot;
</pre>
</div>
<div style="font-family:monospace" class="parity1">
<pre><a class="linenr" href="#l100" id="l100">   100</a> &quot;    float dist;\n&quot;
</pre>
</div>
<div style="font-family:monospace" class="parity0">
<pre><a class="linenr" href="#l101" id="l101">   101</a> &quot;\n&quot;
</pre>
</div>
<div style="font-family:monospace" class="parity1">
<pre><a class="linenr" href="#l102" id="l102">   102</a> &quot;    delta = vec2(0.5, 0.5) - v_texCoord;\n&quot;
</pre>
</div>
<div style="font-family:monospace" class="parity0">
<pre><a class="linenr" href="#l103" id="l103">   103</a> &quot;    dist = dot(delta, delta);\n&quot;
</pre>
</div>
<div style="font-family:monospace" class="parity1">
<pre><a class="linenr" href="#l104" id="l104">   104</a> &quot;\n&quot;
</pre>
</div>
<div style="font-family:monospace" class="parity0">
<pre><a class="linenr" href="#l105" id="l105">   105</a> &quot;    color.r = v_texCoord.x;\n&quot;
</pre>
</div>
<div style="font-family:monospace" class="parity1">
<pre><a class="linenr" href="#l106" id="l106">   106</a> &quot;    color.g = v_texCoord.x * v_texCoord.y;\n&quot;
</pre>
</div>
<div style="font-family:monospace" class="parity0">
<pre><a class="linenr" href="#l107" id="l107">   107</a> &quot;    color.b = v_texCoord.y;\n&quot;
</pre>
</div>
<div style="font-family:monospace" class="parity1">
<pre><a class="linenr" href="#l108" id="l108">   108</a> &quot;    color.a = 1.0 - (dist * 4.0);\n&quot;
</pre>
</div>
<div style="font-family:monospace" class="parity0">
<pre><a class="linenr" href="#l109" id="l109">   109</a> &quot;    gl_FragColor = color;\n&quot;
</pre>
</div>
<div style="font-family:monospace" class="parity1">
<pre><a class="linenr" href="#l110" id="l110">   110</a> &quot;}&quot;
</pre>
</div>
<div style="font-family:monospace" class="parity0">
<pre><a class="linenr" href="#l111" id="l111">   111</a>     },
</pre>
</div>
<div style="font-family:monospace" class="parity1">
<pre><a class="linenr" href="#l112" id="l112">   112</a> };
</pre>
</div>
<div style="font-family:monospace" class="parity0">
<pre><a class="linenr" href="#l113" id="l113">   113</a> 
</pre>
</div>
<div style="font-family:monospace" class="parity1">
<pre><a class="linenr" href="#l114" id="l114">   114</a> static PFNGLATTACHOBJECTARBPROC glAttachObjectARB;
</pre>
</div>
<div style="font-family:monospace" class="parity0">
<pre><a class="linenr" href="#l115" id="l115">   115</a> static PFNGLCOMPILESHADERARBPROC glCompileShaderARB;
</pre>
</div>
<div style="font-family:monospace" class="parity1">
<pre><a class="linenr" href="#l116" id="l116">   116</a> static PFNGLCREATEPROGRAMOBJECTARBPROC glCreateProgramObjectARB;
</pre>
</div>
<div style="font-family:monospace" class="parity0">
<pre><a class="linenr" href="#l117" id="l117">   117</a> static PFNGLCREATESHADEROBJECTARBPROC glCreateShaderObjectARB;
</pre>
</div>
<div style="font-family:monospace" class="parity1">
<pre><a class="linenr" href="#l118" id="l118">   118</a> static PFNGLDELETEOBJECTARBPROC glDeleteObjectARB;
</pre>
</div>
<div style="font-family:monospace" class="parity0">
<pre><a class="linenr" href="#l119" id="l119">   119</a> static PFNGLGETINFOLOGARBPROC glGetInfoLogARB;
</pre>
</div>
<div style="font-family:monospace" class="parity1">
<pre><a class="linenr" href="#l120" id="l120">   120</a> static PFNGLGETOBJECTPARAMETERIVARBPROC glGetObjectParameterivARB;
</pre>
</div>
<div style="font-family:monospace" class="parity0">
<pre><a class="linenr" href="#l121" id="l121">   121</a> static PFNGLGETUNIFORMLOCATIONARBPROC glGetUniformLocationARB;
</pre>
</div>
<div style="font-family:monospace" class="parity1">
<pre><a class="linenr" href="#l122" id="l122">   122</a> static PFNGLLINKPROGRAMARBPROC glLinkProgramARB;
</pre>
</div>
<div style="font-family:monospace" class="parity0">
<pre><a class="linenr" href="#l123" id="l123">   123</a> static PFNGLSHADERSOURCEARBPROC glShaderSourceARB;
</pre>
</div>
<div style="font-family:monospace" class="parity1">
<pre><a class="linenr" href="#l124" id="l124">   124</a> static PFNGLUNIFORM1IARBPROC glUniform1iARB;
</pre>
</div>
<div style="font-family:monospace" class="parity0">
<pre><a class="linenr" href="#l125" id="l125">   125</a> static PFNGLUSEPROGRAMOBJECTARBPROC glUseProgramObjectARB;
</pre>
</div>
<div style="font-family:monospace" class="parity1">
<pre><a class="linenr" href="#l126" id="l126">   126</a> 
</pre>
</div>
<div style="font-family:monospace" class="parity0">
<pre><a class="linenr" href="#l127" id="l127">   127</a> static SDL_bool CompileShader(GLhandleARB shader, const char *source)
</pre>
</div>
<div style="font-family:monospace" class="parity1">
<pre><a class="linenr" href="#l128" id="l128">   128</a> {
</pre>
</div>
<div style="font-family:monospace" class="parity0">
<pre><a class="linenr" href="#l129" id="l129">   129</a>     GLint status;
</pre>
</div>
<div style="font-family:monospace" class="parity1">
<pre><a class="linenr" href="#l130" id="l130">   130</a> 
</pre>
</div>
<div style="font-family:monospace" class="parity0">
<pre><a class="linenr" href="#l131" id="l131">   131</a>     glShaderSourceARB(shader, 1, &amp;source, NULL);
</pre>
</div>
<div style="font-family:monospace" class="parity1">
<pre><a class="linenr" href="#l132" id="l132">   132</a>     glCompileShaderARB(shader);
</pre>
</div>
<div style="font-family:monospace" class="parity0">
<pre><a class="linenr" href="#l133" id="l133">   133</a>     glGetObjectParameterivARB(shader, GL_OBJECT_COMPILE_STATUS_ARB, &amp;status);
</pre>
</div>
<div style="font-family:monospace" class="parity1">
<pre><a class="linenr" href="#l134" id="l134">   134</a>     if (status == 0) {
</pre>
</div>
<div style="font-family:monospace" class="parity0">
<pre><a class="linenr" href="#l135" id="l135">   135</a>         GLint length;
</pre>
</div>
<div style="font-family:monospace" class="parity1">
<pre><a class="linenr" href="#l136" id="l136">   136</a>         char *info;
</pre>
</div>
<div style="font-family:monospace" class="parity0">
<pre><a class="linenr" href="#l137" id="l137">   137</a> 
</pre>
</div>
<div style="font-family:monospace" class="parity1">
<pre><a class="linenr" href="#l138" id="l138">   138</a>         glGetObjectParameterivARB(shader, GL_OBJECT_INFO_LOG_LENGTH_ARB, &amp;length);
</pre>
</div>
<div style="font-family:monospace" class="parity0">
<pre><a class="linenr" href="#l139" id="l139">   139</a>         info = SDL_stack_alloc(char, length+1);
</pre>
</div>
<div style="font-family:monospace" class="parity1">
<pre><a class="linenr" href="#l140" id="l140">   140</a>         glGetInfoLogARB(shader, length, NULL, info);
</pre>
</div>
<div style="font-family:monospace" class="parity0">
<pre><a class="linenr" href="#l141" id="l141">   141</a>         SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, &quot;Failed to compile shader:\n%s\n%s&quot;, source, info);
</pre>
</div>
<div style="font-family:monospace" class="parity1">
<pre><a class="linenr" href="#l142" id="l142">   142</a>         SDL_stack_free(info);
</pre>
</div>
<div style="font-family:monospace" class="parity0">
<pre><a class="linenr" href="#l143" id="l143">   143</a> 
</pre>
</div>
<div style="font-family:monospace" class="parity1">
<pre><a class="linenr" href="#l144" id="l144">   144</a>         return SDL_FALSE;
</pre>
</div>
<div style="font-family:monospace" class="parity0">
<pre><a class="linenr" href="#l145" id="l145">   145</a>     } else {
</pre>
</div>
<div style="font-family:monospace" class="parity1">
<pre><a class="linenr" href="#l146" id="l146">   146</a>         return SDL_TRUE;
</pre>
</div>
<div style="font-family:monospace" class="parity0">
<pre><a class="linenr" href="#l147" id="l147">   147</a>     }
</pre>
</div>
<div style="font-family:monospace" class="parity1">
<pre><a class="linenr" href="#l148" id="l148">   148</a> }
</pre>
</div>
<div style="font-family:monospace" class="parity0">
<pre><a class="linenr" href="#l149" id="l149">   149</a> 
</pre>
</div>
<div style="font-family:monospace" class="parity1">
<pre><a class="linenr" href="#l150" id="l150">   150</a> static SDL_bool CompileShaderProgram(ShaderData *data)
</pre>
</div>
<div style="font-family:monospace" class="parity0">
<pre><a class="linenr" href="#l151" id="l151">   151</a> {
</pre>
</div>
<div style="font-family:monospace" class="parity1">
<pre><a class="linenr" href="#l152" id="l152">   152</a>     const int num_tmus_bound = 4;
</pre>
</div>
<div style="font-family:monospace" class="parity0">
<pre><a class="linenr" href="#l153" id="l153">   153</a>     int i;
</pre>
</div>
<div style="font-family:monospace" class="parity1">
<pre><a class="linenr" href="#l154" id="l154">   154</a>     GLint location;
</pre>
</div>
<div style="font-family:monospace" class="parity0">
<pre><a class="linenr" href="#l155" id="l155">   155</a> 
</pre>
</div>
<div style="font-family:monospace" class="parity1">
<pre><a class="linenr" href="#l156" id="l156">   156</a>     glGetError();
</pre>
</div>
<div style="font-family:monospace" class="parity0">
<pre><a class="linenr" href="#l157" id="l157">   157</a> 
</pre>
</div>
<div style="font-family:monospace" class="parity1">
<pre><a class="linenr" href="#l158" id="l158">   158</a>     /* Create one program object to rule them all */
</pre>
</div>
<div style="font-family:monospace" class="parity0">
<pre><a class="linenr" href="#l159" id="l159">   159</a>     data-&gt;program = glCreateProgramObjectARB();
</pre>
</div>
<div style="font-family:monospace" class="parity1">
<pre><a class="linenr" href="#l160" id="l160">   160</a> 
</pre>
</div>
<div style="font-family:monospace" class="parity0">
<pre><a class="linenr" href="#l161" id="l161">   161</a>     /* Create the vertex shader */
</pre>
</div>
<div style="font-family:monospace" class="parity1">
<pre><a class="linenr" href="#l162" id="l162">   162</a>     data-&gt;vert_shader = glCreateShaderObjectARB(GL_VERTEX_SHADER_ARB);
</pre>
</div>
<div style="font-family:monospace" class="parity0">
<pre><a class="linenr" href="#l163" id="l163">   163</a>     if (!CompileShader(data-&gt;vert_shader, data-&gt;vert_source)) {
</pre>
</div>
<div style="font-family:monospace" class="parity1">
<pre><a class="linenr" href="#l164" id="l164">   164</a>         return SDL_FALSE;
</pre>
</div>
<div style="font-family:monospace" class="parity0">
<pre><a class="linenr" href="#l165" id="l165">   165</a>     }
</pre>
</div>
<div style="font-family:monospace" class="parity1">
<pre><a class="linenr" href="#l166" id="l166">   166</a> 
</pre>
</div>
<div style="font-family:monospace" class="parity0">
<pre><a class="linenr" href="#l167" id="l167">   167</a>     /* Create the fragment shader */
</pre>
</div>
<div style="font-family:monospace" class="parity1">
<pre><a class="linenr" href="#l168" id="l168">   168</a>     data-&gt;frag_shader = glCreateShaderObjectARB(GL_FRAGMENT_SHADER_ARB);
</pre>
</div>
<div style="font-family:monospace" class="parity0">
<pre><a class="linenr" href="#l169" id="l169">   169</a>     if (!CompileShader(data-&gt;frag_shader, data-&gt;frag_source)) {
</pre>
</div>
<div style="font-family:monospace" class="parity1">
<pre><a class="linenr" href="#l170" id="l170">   170</a>         return SDL_FALSE;
</pre>
</div>
<div style="font-family:monospace" class="parity0">
<pre><a class="linenr" href="#l171" id="l171">   171</a>     }
</pre>
</div>
<div style="font-family:monospace" class="parity1">
<pre><a class="linenr" href="#l172" id="l172">   172</a> 
</pre>
</div>
<div style="font-family:monospace" class="parity0">
<pre><a class="linenr" href="#l173" id="l173">   173</a>     /* ... and in the darkness bind them */
</pre>
</div>
<div style="font-family:monospace" class="parity1">
<pre><a class="linenr" href="#l174" id="l174">   174</a>     glAttachObjectARB(data-&gt;program, data-&gt;vert_shader);
</pre>
</div>
<div style="font-family:monospace" class="parity0">
<pre><a class="linenr" href="#l175" id="l175">   175</a>     glAttachObjectARB(data-&gt;program, data-&gt;frag_shader);
</pre>
</div>
<div style="font-family:monospace" class="parity1">
<pre><a class="linenr" href="#l176" id="l176">   176</a>     glLinkProgramARB(data-&gt;program);
</pre>
</div>
<div style="font-family:monospace" class="parity0">
<pre><a class="linenr" href="#l177" id="l177">   177</a> 
</pre>
</div>
<div style="font-family:monospace" class="parity1">
<pre><a class="linenr" href="#l178" id="l178">   178</a>     /* Set up some uniform variables */
</pre>
</div>
<div style="font-family:monospace" class="parity0">
<pre><a class="linenr" href="#l179" id="l179">   179</a>     glUseProgramObjectARB(data-&gt;program);
</pre>
</div>
<div style="font-family:monospace" class="parity1">
<pre><a class="linenr" href="#l180" id="l180">   180</a>     for (i = 0; i &lt; num_tmus_bound; ++i) {
</pre>
</div>
<div style="font-family:monospace" class="parity0">
<pre><a class="linenr" href="#l181" id="l181">   181</a>         char tex_name[5];
</pre>
</div>
<div style="font-family:monospace" class="parity1">
<pre><a class="linenr" href="#l182" id="l182">   182</a>         SDL_snprintf(tex_name, SDL_arraysize(tex_name), &quot;tex%d&quot;, i);
</pre>
</div>
<div style="font-family:monospace" class="parity0">
<pre><a class="linenr" href="#l183" id="l183">   183</a>         location = glGetUniformLocationARB(data-&gt;program, tex_name);
</pre>
</div>
<div style="font-family:monospace" class="parity1">
<pre><a class="linenr" href="#l184" id="l184">   184</a>         if (location &gt;= 0) {
</pre>
</div>
<div style="font-family:monospace" class="parity0">
<pre><a class="linenr" href="#l185" id="l185">   185</a>             glUniform1iARB(location, i);
</pre>
</div>
<div style="font-family:monospace" class="parity1">
<pre><a class="linenr" href="#l186" id="l186">   186</a>         }
</pre>
</div>
<div style="font-family:monospace" class="parity0">
<pre><a class="linenr" href="#l187" id="l187">   187</a>     }
</pre>
</div>
<div style="font-family:monospace" class="parity1">
<pre><a class="linenr" href="#l188" id="l188">   188</a>     glUseProgramObjectARB(0);
</pre>
</div>
<div style="font-family:monospace" class="parity0">
<pre><a class="linenr" href="#l189" id="l189">   189</a> 
</pre>
</div>
<div style="font-family:monospace" class="parity1">
<pre><a class="linenr" href="#l190" id="l190">   190</a>     return (glGetError() == GL_NO_ERROR) ? SDL_TRUE : SDL_FALSE;
</pre>
</div>
<div style="font-family:monospace" class="parity0">
<pre><a class="linenr" href="#l191" id="l191">   191</a> }
</pre>
</div>
<div style="font-family:monospace" class="parity1">
<pre><a class="linenr" href="#l192" id="l192">   192</a> 
</pre>
</div>
<div style="font-family:monospace" class="parity0">
<pre><a class="linenr" href="#l193" id="l193">   193</a> static void DestroyShaderProgram(ShaderData *data)
</pre>
</div>
<div style="font-family:monospace" class="parity1">
<pre><a class="linenr" href="#l194" id="l194">   194</a> {
</pre>
</div>
<div style="font-family:monospace" class="parity0">
<pre><a class="linenr" href="#l195" id="l195">   195</a>     if (shaders_supported) {
</pre>
</div>
<div style="font-family:monospace" class="parity1">
<pre><a class="linenr" href="#l196" id="l196">   196</a>         glDeleteObjectARB(data-&gt;vert_shader);
</pre>
</div>
<div style="font-family:monospace" class="parity0">
<pre><a class="linenr" href="#l197" id="l197">   197</a>         glDeleteObjectARB(data-&gt;frag_shader);
</pre>
</div>
<div style="font-family:monospace" class="parity1">
<pre><a class="linenr" href="#l198" id="l198">   198</a>         glDeleteObjectARB(data-&gt;program);
</pre>
</div>
<div style="font-family:monospace" class="parity0">
<pre><a class="linenr" href="#l199" id="l199">   199</a>     }
</pre>
</div>
<div style="font-family:monospace" class="parity1">
<pre><a class="linenr" href="#l200" id="l200">   200</a> }
</pre>
</div>
<div style="font-family:monospace" class="parity0">
<pre><a class="linenr" href="#l201" id="l201">   201</a> 
</pre>
</div>
<div style="font-family:monospace" class="parity1">
<pre><a class="linenr" href="#l202" id="l202">   202</a> static SDL_bool InitShaders()
</pre>
</div>
<div style="font-family:monospace" class="parity0">
<pre><a class="linenr" href="#l203" id="l203">   203</a> {
</pre>
</div>
<div style="font-family:monospace" class="parity1">
<pre><a class="linenr" href="#l204" id="l204">   204</a>     int i;
</pre>
</div>
<div style="font-family:monospace" class="parity0">
<pre><a class="linenr" href="#l205" id="l205">   205</a> 
</pre>
</div>
<div style="font-family:monospace" class="parity1">
<pre><a class="linenr" href="#l206" id="l206">   206</a>     /* Check for shader support */
</pre>
</div>
<div style="font-family:monospace" class="parity0">
<pre><a class="linenr" href="#l207" id="l207">   207</a>     shaders_supported = SDL_FALSE;
</pre>
</div>
<div style="font-family:monospace" class="parity1">
<pre><a class="linenr" href="#l208" id="l208">   208</a>     if (SDL_GL_ExtensionSupported(&quot;GL_ARB_shader_objects&quot;) &amp;&amp;
</pre>
</div>
<div style="font-family:monospace" class="parity0">
<pre><a class="linenr" href="#l209" id="l209">   209</a>         SDL_GL_ExtensionSupported(&quot;GL_ARB_shading_language_100&quot;) &amp;&amp;
</pre>
</div>
<div style="font-family:monospace" class="parity1">
<pre><a class="linenr" href="#l210" id="l210">   210</a>         SDL_GL_ExtensionSupported(&quot;GL_ARB_vertex_shader&quot;) &amp;&amp;
</pre>
</div>
<div style="font-family:monospace" class="parity0">
<pre><a class="linenr" href="#l211" id="l211">   211</a>         SDL_GL_ExtensionSupported(&quot;GL_ARB_fragment_shader&quot;)) {
</pre>
</div>
<div style="font-family:monospace" class="parity1">
<pre><a class="linenr" href="#l212" id="l212">   212</a>         glAttachObjectARB = (PFNGLATTACHOBJECTARBPROC) SDL_GL_GetProcAddress(&quot;glAttachObjectARB&quot;);
</pre>
</div>
<div style="font-family:monospace" class="parity0">
<pre><a class="linenr" href="#l213" id="l213">   213</a>         glCompileShaderARB = (PFNGLCOMPILESHADERARBPROC) SDL_GL_GetProcAddress(&quot;glCompileShaderARB&quot;);
</pre>
</div>
<div style="font-family:monospace" class="parity1">
<pre><a class="linenr" href="#l214" id="l214">   214</a>         glCreateProgramObjectARB = (PFNGLCREATEPROGRAMOBJECTARBPROC) SDL_GL_GetProcAddress(&quot;glCreateProgramObjectARB&quot;);
</pre>
</div>
<div style="font-family:monospace" class="parity0">
<pre><a class="linenr" href="#l215" id="l215">   215</a>         glCreateShaderObjectARB = (PFNGLCREATESHADEROBJECTARBPROC) SDL_GL_GetProcAddress(&quot;glCreateShaderObjectARB&quot;);
</pre>
</div>
<div style="font-family:monospace" class="parity1">
<pre><a class="linenr" href="#l216" id="l216">   216</a>         glDeleteObjectARB = (PFNGLDELETEOBJECTARBPROC) SDL_GL_GetProcAddress(&quot;glDeleteObjectARB&quot;);
</pre>
</div>
<div style="font-family:monospace" class="parity0">
<pre><a class="linenr" href="#l217" id="l217">   217</a>         glGetInfoLogARB = (PFNGLGETINFOLOGARBPROC) SDL_GL_GetProcAddress(&quot;glGetInfoLogARB&quot;);
</pre>
</div>
<div style="font-family:monospace" class="parity1">
<pre><a class="linenr" href="#l218" id="l218">   218</a>         glGetObjectParameterivARB = (PFNGLGETOBJECTPARAMETERIVARBPROC) SDL_GL_GetProcAddress(&quot;glGetObjectParameterivARB&quot;);
</pre>
</div>
<div style="font-family:monospace" class="parity0">
<pre><a class="linenr" href="#l219" id="l219">   219</a>         glGetUniformLocationARB = (PFNGLGETUNIFORMLOCATIONARBPROC) SDL_GL_GetProcAddress(&quot;glGetUniformLocationARB&quot;);
</pre>
</div>
<div style="font-family:monospace" class="parity1">
<pre><a class="linenr" href="#l220" id="l220">   220</a>         glLinkProgramARB = (PFNGLLINKPROGRAMARBPROC) SDL_GL_GetProcAddress(&quot;glLinkProgramARB&quot;);
</pre>
</div>
<div style="font-family:monospace" class="parity0">
<pre><a class="linenr" href="#l221" id="l221">   221</a>         glShaderSourceARB = (PFNGLSHADERSOURCEARBPROC) SDL_GL_GetProcAddress(&quot;glShaderSourceARB&quot;);
</pre>
</div>
<div style="font-family:monospace" class="parity1">
<pre><a class="linenr" href="#l222" id="l222">   222</a>         glUniform1iARB = (PFNGLUNIFORM1IARBPROC) SDL_GL_GetProcAddress(&quot;glUniform1iARB&quot;);
</pre>
</div>
<div style="font-family:monospace" class="parity0">
<pre><a class="linenr" href="#l223" id="l223">   223</a>         glUseProgramObjectARB = (PFNGLUSEPROGRAMOBJECTARBPROC) SDL_GL_GetProcAddress(&quot;glUseProgramObjectARB&quot;);
</pre>
</div>
<div style="font-family:monospace" class="parity1">
<pre><a class="linenr" href="#l224" id="l224">   224</a>         if (glAttachObjectARB &amp;&amp;
</pre>
</div>
<div style="font-family:monospace" class="parity0">
<pre><a class="linenr" href="#l225" id="l225">   225</a>             glCompileShaderARB &amp;&amp;
</pre>
</div>
<div style="font-family:monospace" class="parity1">
<pre><a class="linenr" href="#l226" id="l226">   226</a>             glCreateProgramObjectARB &amp;&amp;
</pre>
</div>
<div style="font-family:monospace" class="parity0">
<pre><a class="linenr" href="#l227" id="l227">   227</a>             glCreateShaderObjectARB &amp;&amp;
</pre>
</div>
<div style="font-family:monospace" class="parity1">
<pre><a class="linenr" href="#l228" id="l228">   228</a>             glDeleteObjectARB &amp;&amp;
</pre>
</div>
<div style="font-family:monospace" class="parity0">
<pre><a class="linenr" href="#l229" id="l229">   229</a>             glGetInfoLogARB &amp;&amp;
</pre>
</div>
<div style="font-family:monospace" class="parity1">
<pre><a class="linenr" href="#l230" id="l230">   230</a>             glGetObjectParameterivARB &amp;&amp;
</pre>
</div>
<div style="font-family:monospace" class="parity0">
<pre><a class="linenr" href="#l231" id="l231">   231</a>             glGetUniformLocationARB &amp;&amp;
</pre>
</div>
<div style="font-family:monospace" class="parity1">
<pre><a class="linenr" href="#l232" id="l232">   232</a>             glLinkProgramARB &amp;&amp;
</pre>
</div>
<div style="font-family:monospace" class="parity0">
<pre><a class="linenr" href="#l233" id="l233">   233</a>             glShaderSourceARB &amp;&amp;
</pre>
</div>
<div style="font-family:monospace" class="parity1">
<pre><a class="linenr" href="#l234" id="l234">   234</a>             glUniform1iARB &amp;&amp;
</pre>
</div>
<div style="font-family:monospace" class="parity0">
<pre><a class="linenr" href="#l235" id="l235">   235</a>             glUseProgramObjectARB) {
</pre>
</div>
<div style="font-family:monospace" class="parity1">
<pre><a class="linenr" href="#l236" id="l236">   236</a>             shaders_supported = SDL_TRUE;
</pre>
</div>
<div style="font-family:monospace" class="parity0">
<pre><a class="linenr" href="#l237" id="l237">   237</a>         }
</pre>
</div>
<div style="font-family:monospace" class="parity1">
<pre><a class="linenr" href="#l238" id="l238">   238</a>     }
</pre>
</div>
<div style="font-family:monospace" class="parity0">
<pre><a class="linenr" href="#l239" id="l239">   239</a> 
</pre>
</div>
<div style="font-family:monospace" class="parity1">
<pre><a class="linenr" href="#l240" id="l240">   240</a>     if (!shaders_supported) {
</pre>
</div>
<div style="font-family:monospace" class="parity0">
<pre><a class="linenr" href="#l241" id="l241">   241</a>         return SDL_FALSE;
</pre>
</div>
<div style="font-family:monospace" class="parity1">
<pre><a class="linenr" href="#l242" id="l242">   242</a>     }
</pre>
</div>
<div style="font-family:monospace" class="parity0">
<pre><a class="linenr" href="#l243" id="l243">   243</a> 
</pre>
</div>
<div style="font-family:monospace" class="parity1">
<pre><a class="linenr" href="#l244" id="l244">   244</a>     /* Compile all the shaders */
</pre>
</div>
<div style="font-family:monospace" class="parity0">
<pre><a class="linenr" href="#l245" id="l245">   245</a>     for (i = 0; i &lt; NUM_SHADERS; ++i) {
</pre>
</div>
<div style="font-family:monospace" class="parity1">
<pre><a class="linenr" href="#l246" id="l246">   246</a>         if (!CompileShaderProgram(&amp;shaders[i])) {
</pre>
</div>
<div style="font-family:monospace" class="parity0">
<pre><a class="linenr" href="#l247" id="l247">   247</a>             SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, &quot;Unable to compile shader!\n&quot;);
</pre>
</div>
<div style="font-family:monospace" class="parity1">
<pre><a class="linenr" href="#l248" id="l248">   248</a>             return SDL_FALSE;
</pre>
</div>
<div style="font-family:monospace" class="parity0">
<pre><a class="linenr" href="#l249" id="l249">   249</a>         }
</pre>
</div>
<div style="font-family:monospace" class="parity1">
<pre><a class="linenr" href="#l250" id="l250">   250</a>     }
</pre>
</div>
<div style="font-family:monospace" class="parity0">
<pre><a class="linenr" href="#l251" id="l251">   251</a> 
</pre>
</div>
<div style="font-family:monospace" class="parity1">
<pre><a class="linenr" href="#l252" id="l252">   252</a>     /* We're done! */
</pre>
</div>
<div style="font-family:monospace" class="parity0">
<pre><a class="linenr" href="#l253" id="l253">   253</a>     return SDL_TRUE;
</pre>
</div>
<div style="font-family:monospace" class="parity1">
<pre><a class="linenr" href="#l254" id="l254">   254</a> }
</pre>
</div>
<div style="font-family:monospace" class="parity0">
<pre><a class="linenr" href="#l255" id="l255">   255</a> 
</pre>
</div>
<div style="font-family:monospace" class="parity1">
<pre><a class="linenr" href="#l256" id="l256">   256</a> static void QuitShaders()
</pre>
</div>
<div style="font-family:monospace" class="parity0">
<pre><a class="linenr" href="#l257" id="l257">   257</a> {
</pre>
</div>
<div style="font-family:monospace" class="parity1">
<pre><a class="linenr" href="#l258" id="l258">   258</a>     int i;
</pre>
</div>
<div style="font-family:monospace" class="parity0">
<pre><a class="linenr" href="#l259" id="l259">   259</a> 
</pre>
</div>
<div style="font-family:monospace" class="parity1">
<pre><a class="linenr" href="#l260" id="l260">   260</a>     for (i = 0; i &lt; NUM_SHADERS; ++i) {
</pre>
</div>
<div style="font-family:monospace" class="parity0">
<pre><a class="linenr" href="#l261" id="l261">   261</a>         DestroyShaderProgram(&amp;shaders[i]);
</pre>
</div>
<div style="font-family:monospace" class="parity1">
<pre><a class="linenr" href="#l262" id="l262">   262</a>     }
</pre>
</div>
<div style="font-family:monospace" class="parity0">
<pre><a class="linenr" href="#l263" id="l263">   263</a> }
</pre>
</div>
<div style="font-family:monospace" class="parity1">
<pre><a class="linenr" href="#l264" id="l264">   264</a> 
</pre>
</div>
<div style="font-family:monospace" class="parity0">
<pre><a class="linenr" href="#l265" id="l265">   265</a> /* Quick utility function for texture creation */
</pre>
</div>
<div style="font-family:monospace" class="parity1">
<pre><a class="linenr" href="#l266" id="l266">   266</a> static int
</pre>
</div>
<div style="font-family:monospace" class="parity0">
<pre><a class="linenr" href="#l267" id="l267">   267</a> power_of_two(int input)
</pre>
</div>
<div style="font-family:monospace" class="parity1">
<pre><a class="linenr" href="#l268" id="l268">   268</a> {
</pre>
</div>
<div style="font-family:monospace" class="parity0">
<pre><a class="linenr" href="#l269" id="l269">   269</a>     int value = 1;
</pre>
</div>
<div style="font-family:monospace" class="parity1">
<pre><a class="linenr" href="#l270" id="l270">   270</a> 
</pre>
</div>
<div style="font-family:monospace" class="parity0">
<pre><a class="linenr" href="#l271" id="l271">   271</a>     while (value &lt; input) {
</pre>
</div>
<div style="font-family:monospace" class="parity1">
<pre><a class="linenr" href="#l272" id="l272">   272</a>         value &lt;&lt;= 1;
</pre>
</div>
<div style="font-family:monospace" class="parity0">
<pre><a class="linenr" href="#l273" id="l273">   273</a>     }
</pre>
</div>
<div style="font-family:monospace" class="parity1">
<pre><a class="linenr" href="#l274" id="l274">   274</a>     return value;
</pre>
</div>
<div style="font-family:monospace" class="parity0">
<pre><a class="linenr" href="#l275" id="l275">   275</a> }
</pre>
</div>
<div style="font-family:monospace" class="parity1">
<pre><a class="linenr" href="#l276" id="l276">   276</a> 
</pre>
</div>
<div style="font-family:monospace" class="parity0">
<pre><a class="linenr" href="#l277" id="l277">   277</a> GLuint
</pre>
</div>
<div style="font-family:monospace" class="parity1">
<pre><a class="linenr" href="#l278" id="l278">   278</a> SDL_GL_LoadTexture(SDL_Surface * surface, GLfloat * texcoord)
</pre>
</div>
<div style="font-family:monospace" class="parity0">
<pre><a class="linenr" href="#l279" id="l279">   279</a> {
</pre>
</div>
<div style="font-family:monospace" class="parity1">
<pre><a class="linenr" href="#l280" id="l280">   280</a>     GLuint texture;
</pre>
</div>
<div style="font-family:monospace" class="parity0">
<pre><a class="linenr" href="#l281" id="l281">   281</a>     int w, h;
</pre>
</div>
<div style="font-family:monospace" class="parity1">
<pre><a class="linenr" href="#l282" id="l282">   282</a>     SDL_Surface *image;
</pre>
</div>
<div style="font-family:monospace" class="parity0">
<pre><a class="linenr" href="#l283" id="l283">   283</a>     SDL_Rect area;
</pre>
</div>
<div style="font-family:monospace" class="parity1">
<pre><a class="linenr" href="#l284" id="l284">   284</a>     SDL_BlendMode saved_mode;
</pre>
</div>
<div style="font-family:monospace" class="parity0">
<pre><a class="linenr" href="#l285" id="l285">   285</a> 
</pre>
</div>
<div style="font-family:monospace" class="parity1">
<pre><a class="linenr" href="#l286" id="l286">   286</a>     /* Use the surface width and height expanded to powers of 2 */
</pre>
</div>
<div style="font-family:monospace" class="parity0">
<pre><a class="linenr" href="#l287" id="l287">   287</a>     w = power_of_two(surface-&gt;w);
</pre>
</div>
<div style="font-family:monospace" class="parity1">
<pre><a class="linenr" href="#l288" id="l288">   288</a>     h = power_of_two(surface-&gt;h);
</pre>
</div>
<div style="font-family:monospace" class="parity0">
<pre><a class="linenr" href="#l289" id="l289">   289</a>     texcoord[0] = 0.0f;         /* Min X */
</pre>
</div>
<div style="font-family:monospace" class="parity1">
<pre><a class="linenr" href="#l290" id="l290">   290</a>     texcoord[1] = 0.0f;         /* Min Y */
</pre>
</div>
<div style="font-family:monospace" class="parity0">
<pre><a class="linenr" href="#l291" id="l291">   291</a>     texcoord[2] = (GLfloat) surface-&gt;w / w;     /* Max X */
</pre>
</div>
<div style="font-family:monospace" class="parity1">
<pre><a class="linenr" href="#l292" id="l292">   292</a>     texcoord[3] = (GLfloat) surface-&gt;h / h;     /* Max Y */
</pre>
</div>
<div style="font-family:monospace" class="parity0">
<pre><a class="linenr" href="#l293" id="l293">   293</a> 
</pre>
</div>
<div style="font-family:monospace" class="parity1">
<pre><a class="linenr" href="#l294" id="l294">   294</a>     image = SDL_CreateRGBSurface(SDL_SWSURFACE, w, h, 32,
</pre>
</div>
<div style="font-family:monospace" class="parity0">
<pre><a class="linenr" href="#l295" id="l295">   295</a> #if SDL_BYTEORDER == SDL_LIL_ENDIAN     /* OpenGL RGBA masks */
</pre>
</div>
<div style="font-family:monospace" class="parity1">
<pre><a class="linenr" href="#l296" id="l296">   296</a>                                  0x000000FF,
</pre>
</div>
<div style="font-family:monospace" class="parity0">
<pre><a class="linenr" href="#l297" id="l297">   297</a>                                  0x0000FF00, 0x00FF0000, 0xFF000000
</pre>
</div>
<div style="font-family:monospace" class="parity1">
<pre><a class="linenr" href="#l298" id="l298">   298</a> #else
</pre>
</div>
<div style="font-family:monospace" class="parity0">
<pre><a class="linenr" href="#l299" id="l299">   299</a>                                  0xFF000000,
</pre>
</div>
<div style="font-family:monospace" class="parity1">
<pre><a class="linenr" href="#l300" id="l300">   300</a>                                  0x00FF0000, 0x0000FF00, 0x000000FF
</pre>
</div>
<div style="font-family:monospace" class="parity0">
<pre><a class="linenr" href="#l301" id="l301">   301</a> #endif
</pre>
</div>
<div style="font-family:monospace" class="parity1">
<pre><a class="linenr" href="#l302" id="l302">   302</a>         );
</pre>
</div>
<div style="font-family:monospace" class="parity0">
<pre><a class="linenr" href="#l303" id="l303">   303</a>     if (image == NULL) {
</pre>
</div>
<div style="font-family:monospace" class="parity1">
<pre><a class="linenr" href="#l304" id="l304">   304</a>         return 0;
</pre>
</div>
<div style="font-family:monospace" class="parity0">
<pre><a class="linenr" href="#l305" id="l305">   305</a>     }
</pre>
</div>
<div style="font-family:monospace" class="parity1">
<pre><a class="linenr" href="#l306" id="l306">   306</a> 
</pre>
</div>
<div style="font-family:monospace" class="parity0">
<pre><a class="linenr" href="#l307" id="l307">   307</a>     /* Save the alpha blending attributes */
</pre>
</div>
<div style="font-family:monospace" class="parity1">
<pre><a class="linenr" href="#l308" id="l308">   308</a>     SDL_GetSurfaceBlendMode(surface, &amp;saved_mode);
</pre>
</div>
<div style="font-family:monospace" class="parity0">
<pre><a class="linenr" href="#l309" id="l309">   309</a>     SDL_SetSurfaceBlendMode(surface, SDL_BLENDMODE_NONE);
</pre>
</div>
<div style="font-family:monospace" class="parity1">
<pre><a class="linenr" href="#l310" id="l310">   310</a> 
</pre>
</div>
<div style="font-family:monospace" class="parity0">
<pre><a class="linenr" href="#l311" id="l311">   311</a>     /* Copy the surface into the GL texture image */
</pre>
</div>
<div style="font-family:monospace" class="parity1">
<pre><a class="linenr" href="#l312" id="l312">   312</a>     area.x = 0;
</pre>
</div>
<div style="font-family:monospace" class="parity0">
<pre><a class="linenr" href="#l313" id="l313">   313</a>     area.y = 0;
</pre>
</div>
<div style="font-family:monospace" class="parity1">
<pre><a class="linenr" href="#l314" id="l314">   314</a>     area.w = surface-&gt;w;
</pre>
</div>
<div style="font-family:monospace" class="parity0">
<pre><a class="linenr" href="#l315" id="l315">   315</a>     area.h = surface-&gt;h;
</pre>
</div>
<div style="font-family:monospace" class="parity1">
<pre><a class="linenr" href="#l316" id="l316">   316</a>     SDL_BlitSurface(surface, &amp;area, image, &amp;area);
</pre>
</div>
<div style="font-family:monospace" class="parity0">
<pre><a class="linenr" href="#l317" id="l317">   317</a> 
</pre>
</div>
<div style="font-family:monospace" class="parity1">
<pre><a class="linenr" href="#l318" id="l318">   318</a>     /* Restore the alpha blending attributes */
</pre>
</div>
<div style="font-family:monospace" class="parity0">
<pre><a class="linenr" href="#l319" id="l319">   319</a>     SDL_SetSurfaceBlendMode(surface, saved_mode);
</pre>
</div>
<div style="font-family:monospace" class="parity1">
<pre><a class="linenr" href="#l320" id="l320">   320</a> 
</pre>
</div>
<div style="font-family:monospace" class="parity0">
<pre><a class="linenr" href="#l321" id="l321">   321</a>     /* Create an OpenGL texture for the image */
</pre>
</div>
<div style="font-family:monospace" class="parity1">
<pre><a class="linenr" href="#l322" id="l322">   322</a>     glGenTextures(1, &amp;texture);
</pre>
</div>
<div style="font-family:monospace" class="parity0">
<pre><a class="linenr" href="#l323" id="l323">   323</a>     glBindTexture(GL_TEXTURE_2D, texture);
</pre>
</div>
<div style="font-family:monospace" class="parity1">
<pre><a class="linenr" href="#l324" id="l324">   324</a>     glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
</pre>
</div>
<div style="font-family:monospace" class="parity0">
<pre><a class="linenr" href="#l325" id="l325">   325</a>     glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
</pre>
</div>
<div style="font-family:monospace" class="parity1">
<pre><a class="linenr" href="#l326" id="l326">   326</a>     glTexImage2D(GL_TEXTURE_2D,
</pre>
</div>
<div style="font-family:monospace" class="parity0">
<pre><a class="linenr" href="#l327" id="l327">   327</a>                  0,
</pre>
</div>
<div style="font-family:monospace" class="parity1">
<pre><a class="linenr" href="#l328" id="l328">   328</a>                  GL_RGBA, w, h, 0, GL_RGBA, GL_UNSIGNED_BYTE, image-&gt;pixels);
</pre>
</div>
<div style="font-family:monospace" class="parity0">
<pre><a class="linenr" href="#l329" id="l329">   329</a>     SDL_FreeSurface(image);     /* No longer needed */
</pre>
</div>
<div style="font-family:monospace" class="parity1">
<pre><a class="linenr" href="#l330" id="l330">   330</a> 
</pre>
</div>
<div style="font-family:monospace" class="parity0">
<pre><a class="linenr" href="#l331" id="l331">   331</a>     return texture;
</pre>
</div>
<div style="font-family:monospace" class="parity1">
<pre><a class="linenr" href="#l332" id="l332">   332</a> }
</pre>
</div>
<div style="font-family:monospace" class="parity0">
<pre><a class="linenr" href="#l333" id="l333">   333</a> 
</pre>
</div>
<div style="font-family:monospace" class="parity1">
<pre><a class="linenr" href="#l334" id="l334">   334</a> /* A general OpenGL initialization function.    Sets all of the initial parameters. */
</pre>
</div>
<div style="font-family:monospace" class="parity0">
<pre><a class="linenr" href="#l335" id="l335">   335</a> void InitGL(int Width, int Height)                    /* We call this right after our OpenGL window is created. */
</pre>
</div>
<div style="font-family:monospace" class="parity1">
<pre><a class="linenr" href="#l336" id="l336">   336</a> {
</pre>
</div>
<div style="font-family:monospace" class="parity0">
<pre><a class="linenr" href="#l337" id="l337">   337</a>     GLdouble aspect;
</pre>
</div>
<div style="font-family:monospace" class="parity1">
<pre><a class="linenr" href="#l338" id="l338">   338</a> 
</pre>
</div>
<div style="font-family:monospace" class="parity0">
<pre><a class="linenr" href="#l339" id="l339">   339</a>     glViewport(0, 0, Width, Height);
</pre>
</div>
<div style="font-family:monospace" class="parity1">
<pre><a class="linenr" href="#l340" id="l340">   340</a>     glClearColor(0.0f, 0.0f, 0.0f, 0.0f);        /* This Will Clear The Background Color To Black */
</pre>
</div>
<div style="font-family:monospace" class="parity0">
<pre><a class="linenr" href="#l341" id="l341">   341</a>     glClearDepth(1.0);                /* Enables Clearing Of The Depth Buffer */
</pre>
</div>
<div style="font-family:monospace" class="parity1">
<pre><a class="linenr" href="#l342" id="l342">   342</a>     glDepthFunc(GL_LESS);                /* The Type Of Depth Test To Do */
</pre>
</div>
<div style="font-family:monospace" class="parity0">
<pre><a class="linenr" href="#l343" id="l343">   343</a>     glEnable(GL_DEPTH_TEST);            /* Enables Depth Testing */
</pre>
</div>
<div style="font-family:monospace" class="parity1">
<pre><a class="linenr" href="#l344" id="l344">   344</a>     glShadeModel(GL_SMOOTH);            /* Enables Smooth Color Shading */
</pre>
</div>
<div style="font-family:monospace" class="parity0">
<pre><a class="linenr" href="#l345" id="l345">   345</a> 
</pre>
</div>
<div style="font-family:monospace" class="parity1">
<pre><a class="linenr" href="#l346" id="l346">   346</a>     glMatrixMode(GL_PROJECTION);
</pre>
</div>
<div style="font-family:monospace" class="parity0">
<pre><a class="linenr" href="#l347" id="l347">   347</a>     glLoadIdentity();                /* Reset The Projection Matrix */
</pre>
</div>
<div style="font-family:monospace" class="parity1">
<pre><a class="linenr" href="#l348" id="l348">   348</a> 
</pre>
</div>
<div style="font-family:monospace" class="parity0">
<pre><a class="linenr" href="#l349" id="l349">   349</a>     aspect = (GLdouble)Width / Height;
</pre>
</div>
<div style="font-family:monospace" class="parity1">
<pre><a class="linenr" href="#l350" id="l350">   350</a>     glOrtho(-3.0, 3.0, -3.0 / aspect, 3.0 / aspect, 0.0, 1.0);
</pre>
</div>
<div style="font-family:monospace" class="parity0">
<pre><a class="linenr" href="#l351" id="l351">   351</a> 
</pre>
</div>
<div style="font-family:monospace" class="parity1">
<pre><a class="linenr" href="#l352" id="l352">   352</a>     glMatrixMode(GL_MODELVIEW);
</pre>
</div>
<div style="font-family:monospace" class="parity0">
<pre><a class="linenr" href="#l353" id="l353">   353</a> }
</pre>
</div>
<div style="font-family:monospace" class="parity1">
<pre><a class="linenr" href="#l354" id="l354">   354</a> 
</pre>
</div>
<div style="font-family:monospace" class="parity0">
<pre><a class="linenr" href="#l355" id="l355">   355</a> /* The main drawing function. */
</pre>
</div>
<div style="font-family:monospace" class="parity1">
<pre><a class="linenr" href="#l356" id="l356">   356</a> void DrawGLScene(SDL_Window *window, GLuint texture, GLfloat * texcoord)
</pre>
</div>
<div style="font-family:monospace" class="parity0">
<pre><a class="linenr" href="#l357" id="l357">   357</a> {
</pre>
</div>
<div style="font-family:monospace" class="parity1">
<pre><a class="linenr" href="#l358" id="l358">   358</a>     /* Texture coordinate lookup, to make it simple */
</pre>
</div>
<div style="font-family:monospace" class="parity0">
<pre><a class="linenr" href="#l359" id="l359">   359</a>     enum {
</pre>
</div>
<div style="font-family:monospace" class="parity1">
<pre><a class="linenr" href="#l360" id="l360">   360</a>         MINX,
</pre>
</div>
<div style="font-family:monospace" class="parity0">
<pre><a class="linenr" href="#l361" id="l361">   361</a>         MINY,
</pre>
</div>
<div style="font-family:monospace" class="parity1">
<pre><a class="linenr" href="#l362" id="l362">   362</a>         MAXX,
</pre>
</div>
<div style="font-family:monospace" class="parity0">
<pre><a class="linenr" href="#l363" id="l363">   363</a>         MAXY
</pre>
</div>
<div style="font-family:monospace" class="parity1">
<pre><a class="linenr" href="#l364" id="l364">   364</a>     };
</pre>
</div>
<div style="font-family:monospace" class="parity0">
<pre><a class="linenr" href="#l365" id="l365">   365</a> 
</pre>
</div>
<div style="font-family:monospace" class="parity1">
<pre><a class="linenr" href="#l366" id="l366">   366</a>     glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);        /* Clear The Screen And The Depth Buffer */
</pre>
</div>
<div style="font-family:monospace" class="parity0">
<pre><a class="linenr" href="#l367" id="l367">   367</a>     glLoadIdentity();                /* Reset The View */
</pre>
</div>
<div style="font-family:monospace" class="parity1">
<pre><a class="linenr" href="#l368" id="l368">   368</a> 
</pre>
</div>
<div style="font-family:monospace" class="parity0">
<pre><a class="linenr" href="#l369" id="l369">   369</a>     glTranslatef(-1.5f,0.0f,0.0f);        /* Move Left 1.5 Units */
</pre>
</div>
<div style="font-family:monospace" class="parity1">
<pre><a class="linenr" href="#l370" id="l370">   370</a> 
</pre>
</div>
<div style="font-family:monospace" class="parity0">
<pre><a class="linenr" href="#l371" id="l371">   371</a>     /* draw a triangle (in smooth coloring mode) */
</pre>
</div>
<div style="font-family:monospace" class="parity1">
<pre><a class="linenr" href="#l372" id="l372">   372</a>     glBegin(GL_POLYGON);                /* start drawing a polygon */
</pre>
</div>
<div style="font-family:monospace" class="parity0">
<pre><a class="linenr" href="#l373" id="l373">   373</a>     glColor3f(1.0f,0.0f,0.0f);            /* Set The Color To Red */
</pre>
</div>
<div style="font-family:monospace" class="parity1">
<pre><a class="linenr" href="#l374" id="l374">   374</a>     glVertex3f( 0.0f, 1.0f, 0.0f);        /* Top */
</pre>
</div>
<div style="font-family:monospace" class="parity0">
<pre><a class="linenr" href="#l375" id="l375">   375</a>     glColor3f(0.0f,1.0f,0.0f);            /* Set The Color To Green */
</pre>
</div>
<div style="font-family:monospace" class="parity1">
<pre><a class="linenr" href="#l376" id="l376">   376</a>     glVertex3f( 1.0f,-1.0f, 0.0f);        /* Bottom Right */
</pre>
</div>
<div style="font-family:monospace" class="parity0">
<pre><a class="linenr" href="#l377" id="l377">   377</a>     glColor3f(0.0f,0.0f,1.0f);            /* Set The Color To Blue */
</pre>
</div>
<div style="font-family:monospace" class="parity1">
<pre><a class="linenr" href="#l378" id="l378">   378</a>     glVertex3f(-1.0f,-1.0f, 0.0f);        /* Bottom Left */
</pre>
</div>
<div style="font-family:monospace" class="parity0">
<pre><a class="linenr" href="#l379" id="l379">   379</a>     glEnd();                    /* we're done with the polygon (smooth color interpolation) */
</pre>
</div>
<div style="font-family:monospace" class="parity1">
<pre><a class="linenr" href="#l380" id="l380">   380</a> 
</pre>
</div>
<div style="font-family:monospace" class="parity0">
<pre><a class="linenr" href="#l381" id="l381">   381</a>     glTranslatef(3.0f,0.0f,0.0f);         /* Move Right 3 Units */
</pre>
</div>
<div style="font-family:monospace" class="parity1">
<pre><a class="linenr" href="#l382" id="l382">   382</a> 
</pre>
</div>
<div style="font-family:monospace" class="parity0">
<pre><a class="linenr" href="#l383" id="l383">   383</a>     /* Enable blending */
</pre>
</div>
<div style="font-family:monospace" class="parity1">
<pre><a class="linenr" href="#l384" id="l384">   384</a>     glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
</pre>
</div>
<div style="font-family:monospace" class="parity0">
<pre><a class="linenr" href="#l385" id="l385">   385</a>     glEnable(GL_BLEND);
</pre>
</div>
<div style="font-family:monospace" class="parity1">
<pre><a class="linenr" href="#l386" id="l386">   386</a>     glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
</pre>
</div>
<div style="font-family:monospace" class="parity0">
<pre><a class="linenr" href="#l387" id="l387">   387</a> 
</pre>
</div>
<div style="font-family:monospace" class="parity1">
<pre><a class="linenr" href="#l388" id="l388">   388</a>     /* draw a textured square (quadrilateral) */
</pre>
</div>
<div style="font-family:monospace" class="parity0">
<pre><a class="linenr" href="#l389" id="l389">   389</a>     glEnable(GL_TEXTURE_2D);
</pre>
</div>
<div style="font-family:monospace" class="parity1">
<pre><a class="linenr" href="#l390" id="l390">   390</a>     glBindTexture(GL_TEXTURE_2D, texture);
</pre>
</div>
<div style="font-family:monospace" class="parity0">
<pre><a class="linenr" href="#l391" id="l391">   391</a>     glColor3f(1.0f,1.0f,1.0f);
</pre>
</div>
<div style="font-family:monospace" class="parity1">
<pre><a class="linenr" href="#l392" id="l392">   392</a>     if (shaders_supported) {
</pre>
</div>
<div style="font-family:monospace" class="parity0">
<pre><a class="linenr" href="#l393" id="l393">   393</a>         glUseProgramObjectARB(shaders[current_shader].program);
</pre>
</div>
<div style="font-family:monospace" class="parity1">
<pre><a class="linenr" href="#l394" id="l394">   394</a>     }
</pre>
</div>
<div style="font-family:monospace" class="parity0">
<pre><a class="linenr" href="#l395" id="l395">   395</a> 
</pre>
</div>
<div style="font-family:monospace" class="parity1">
<pre><a class="linenr" href="#l396" id="l396">   396</a>     glBegin(GL_QUADS);                /* start drawing a polygon (4 sided) */
</pre>
</div>
<div style="font-family:monospace" class="parity0">
<pre><a class="linenr" href="#l397" id="l397">   397</a>     glTexCoord2f(texcoord[MINX], texcoord[MINY]);
</pre>
</div>
<div style="font-family:monospace" class="parity1">
<pre><a class="linenr" href="#l398" id="l398">   398</a>     glVertex3f(-1.0f, 1.0f, 0.0f);        /* Top Left */
</pre>
</div>
<div style="font-family:monospace" class="parity0">
<pre><a class="linenr" href="#l399" id="l399">   399</a>     glTexCoord2f(texcoord[MAXX], texcoord[MINY]);
</pre>
</div>
<div style="font-family:monospace" class="parity1">
<pre><a class="linenr" href="#l400" id="l400">   400</a>     glVertex3f( 1.0f, 1.0f, 0.0f);        /* Top Right */
</pre>
</div>
<div style="font-family:monospace" class="parity0">
<pre><a class="linenr" href="#l401" id="l401">   401</a>     glTexCoord2f(texcoord[MAXX], texcoord[MAXY]);
</pre>
</div>
<div style="font-family:monospace" class="parity1">
<pre><a class="linenr" href="#l402" id="l402">   402</a>     glVertex3f( 1.0f,-1.0f, 0.0f);        /* Bottom Right */
</pre>
</div>
<div style="font-family:monospace" class="parity0">
<pre><a class="linenr" href="#l403" id="l403">   403</a>     glTexCoord2f(texcoord[MINX], texcoord[MAXY]);
</pre>
</div>
<div style="font-family:monospace" class="parity1">
<pre><a class="linenr" href="#l404" id="l404">   404</a>     glVertex3f(-1.0f,-1.0f, 0.0f);        /* Bottom Left */
</pre>
</div>
<div style="font-family:monospace" class="parity0">
<pre><a class="linenr" href="#l405" id="l405">   405</a>     glEnd();                    /* done with the polygon */
</pre>
</div>
<div style="font-family:monospace" class="parity1">
<pre><a class="linenr" href="#l406" id="l406">   406</a> 
</pre>
</div>
<div style="font-family:monospace" class="parity0">
<pre><a class="linenr" href="#l407" id="l407">   407</a>     if (shaders_supported) {
</pre>
</div>
<div style="font-family:monospace" class="parity1">
<pre><a class="linenr" href="#l408" id="l408">   408</a>         glUseProgramObjectARB(0);
</pre>
</div>
<div style="font-family:monospace" class="parity0">
<pre><a class="linenr" href="#l409" id="l409">   409</a>     }
</pre>
</div>
<div style="font-family:monospace" class="parity1">
<pre><a class="linenr" href="#l410" id="l410">   410</a>     glDisable(GL_TEXTURE_2D);
</pre>
</div>
<div style="font-family:monospace" class="parity0">
<pre><a class="linenr" href="#l411" id="l411">   411</a> 
</pre>
</div>
<div style="font-family:monospace" class="parity1">
<pre><a class="linenr" href="#l412" id="l412">   412</a>     /* swap buffers to display, since we're double buffered. */
</pre>
</div>
<div style="font-family:monospace" class="parity0">
<pre><a class="linenr" href="#l413" id="l413">   413</a>     SDL_GL_SwapWindow(window);
</pre>
</div>
<div style="font-family:monospace" class="parity1">
<pre><a class="linenr" href="#l414" id="l414">   414</a> }
</pre>
</div>
<div style="font-family:monospace" class="parity0">
<pre><a class="linenr" href="#l415" id="l415">   415</a> 
</pre>
</div>
<div style="font-family:monospace" class="parity1">
<pre><a class="linenr" href="#l416" id="l416">   416</a> int main(int argc, char **argv)
</pre>
</div>
<div style="font-family:monospace" class="parity0">
<pre><a class="linenr" href="#l417" id="l417">   417</a> {
</pre>
</div>
<div style="font-family:monospace" class="parity1">
<pre><a class="linenr" href="#l418" id="l418">   418</a>     int done;
</pre>
</div>
<div style="font-family:monospace" class="parity0">
<pre><a class="linenr" href="#l419" id="l419">   419</a>     SDL_Window *window;
</pre>
</div>
<div style="font-family:monospace" class="parity1">
<pre><a class="linenr" href="#l420" id="l420">   420</a>     SDL_Surface *surface;
</pre>
</div>
<div style="font-family:monospace" class="parity0">
<pre><a class="linenr" href="#l421" id="l421">   421</a>     GLuint texture;
</pre>
</div>
<div style="font-family:monospace" class="parity1">
<pre><a class="linenr" href="#l422" id="l422">   422</a>     GLfloat texcoords[4];
</pre>
</div>
<div style="font-family:monospace" class="parity0">
<pre><a class="linenr" href="#l423" id="l423">   423</a> 
</pre>
</div>
<div style="font-family:monospace" class="parity1">
<pre><a class="linenr" href="#l424" id="l424">   424</a> 	/* Enable standard application logging */
</pre>
</div>
<div style="font-family:monospace" class="parity0">
<pre><a class="linenr" href="#l425" id="l425">   425</a>     SDL_LogSetPriority(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_INFO);
</pre>
</div>
<div style="font-family:monospace" class="parity1">
<pre><a class="linenr" href="#l426" id="l426">   426</a> 
</pre>
</div>
<div style="font-family:monospace" class="parity0">
<pre><a class="linenr" href="#l427" id="l427">   427</a>     /* Initialize SDL for video output */
</pre>
</div>
<div style="font-family:monospace" class="parity1">
<pre><a class="linenr" href="#l428" id="l428">   428</a>     if ( SDL_Init(SDL_INIT_VIDEO) &lt; 0 ) {
</pre>
</div>
<div style="font-family:monospace" class="parity0">
<pre><a class="linenr" href="#l429" id="l429">   429</a>         SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, &quot;Unable to initialize SDL: %s\n&quot;, SDL_GetError());
</pre>
</div>
<div style="font-family:monospace" class="parity1">
<pre><a class="linenr" href="#l430" id="l430">   430</a>         exit(1);
</pre>
</div>
<div style="font-family:monospace" class="parity0">
<pre><a class="linenr" href="#l431" id="l431">   431</a>     }
</pre>
</div>
<div style="font-family:monospace" class="parity1">
<pre><a class="linenr" href="#l432" id="l432">   432</a> 
</pre>
</div>
<div style="font-family:monospace" class="parity0">
<pre><a class="linenr" href="#l433" id="l433">   433</a>     /* Create a 640x480 OpenGL screen */
</pre>
</div>
<div style="font-family:monospace" class="parity1">
<pre><a class="linenr" href="#l434" id="l434">   434</a>     window = SDL_CreateWindow( &quot;Shader Demo&quot;, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, SDL_WINDOW_OPENGL );
</pre>
</div>
<div style="font-family:monospace" class="parity0">
<pre><a class="linenr" href="#l435" id="l435">   435</a>     if ( !window ) {
</pre>
</div>
<div style="font-family:monospace" class="parity1">
<pre><a class="linenr" href="#l436" id="l436">   436</a>         SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, &quot;Unable to create OpenGL window: %s\n&quot;, SDL_GetError());
</pre>
</div>
<div style="font-family:monospace" class="parity0">
<pre><a class="linenr" href="#l437" id="l437">   437</a>         SDL_Quit();
</pre>
</div>
<div style="font-family:monospace" class="parity1">
<pre><a class="linenr" href="#l438" id="l438">   438</a>         exit(2);
</pre>
</div>
<div style="font-family:monospace" class="parity0">
<pre><a class="linenr" href="#l439" id="l439">   439</a>     }
</pre>
</div>
<div style="font-family:monospace" class="parity1">
<pre><a class="linenr" href="#l440" id="l440">   440</a> 
</pre>
</div>
<div style="font-family:monospace" class="parity0">
<pre><a class="linenr" href="#l441" id="l441">   441</a>     if ( !SDL_GL_CreateContext(window)) {
</pre>
</div>
<div style="font-family:monospace" class="parity1">
<pre><a class="linenr" href="#l442" id="l442">   442</a>         SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, &quot;Unable to create OpenGL context: %s\n&quot;, SDL_GetError());
</pre>
</div>
<div style="font-family:monospace" class="parity0">
<pre><a class="linenr" href="#l443" id="l443">   443</a>         SDL_Quit();
</pre>
</div>
<div style="font-family:monospace" class="parity1">
<pre><a class="linenr" href="#l444" id="l444">   444</a>         exit(2);
</pre>
</div>
<div style="font-family:monospace" class="parity0">
<pre><a class="linenr" href="#l445" id="l445">   445</a>     }
</pre>
</div>
<div style="font-family:monospace" class="parity1">
<pre><a class="linenr" href="#l446" id="l446">   446</a> 
</pre>
</div>
<div style="font-family:monospace" class="parity0">
<pre><a class="linenr" href="#l447" id="l447">   447</a>     surface = SDL_LoadBMP(&quot;icon.bmp&quot;);
</pre>
</div>
<div style="font-family:monospace" class="parity1">
<pre><a class="linenr" href="#l448" id="l448">   448</a>     if ( ! surface ) {
</pre>
</div>
<div style="font-family:monospace" class="parity0">
<pre><a class="linenr" href="#l449" id="l449">   449</a>         SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, &quot;Unable to load icon.bmp: %s\n&quot;, SDL_GetError());
</pre>
</div>
<div style="font-family:monospace" class="parity1">
<pre><a class="linenr" href="#l450" id="l450">   450</a>         SDL_Quit();
</pre>
</div>
<div style="font-family:monospace" class="parity0">
<pre><a class="linenr" href="#l451" id="l451">   451</a>         exit(3);
</pre>
</div>
<div style="font-family:monospace" class="parity1">
<pre><a class="linenr" href="#l452" id="l452">   452</a>     }
</pre>
</div>
<div style="font-family:monospace" class="parity0">
<pre><a class="linenr" href="#l453" id="l453">   453</a>     texture = SDL_GL_LoadTexture(surface, texcoords);
</pre>
</div>
<div style="font-family:monospace" class="parity1">
<pre><a class="linenr" href="#l454" id="l454">   454</a>     SDL_FreeSurface(surface);
</pre>
</div>
<div style="font-family:monospace" class="parity0">
<pre><a class="linenr" href="#l455" id="l455">   455</a> 
</pre>
</div>
<div style="font-family:monospace" class="parity1">
<pre><a class="linenr" href="#l456" id="l456">   456</a>     /* Loop, drawing and checking events */
</pre>
</div>
<div style="font-family:monospace" class="parity0">
<pre><a class="linenr" href="#l457" id="l457">   457</a>     InitGL(640, 480);
</pre>
</div>
<div style="font-family:monospace" class="parity1">
<pre><a class="linenr" href="#l458" id="l458">   458</a>     if (InitShaders()) {
</pre>
</div>
<div style="font-family:monospace" class="parity0">
<pre><a class="linenr" href="#l459" id="l459">   459</a>         SDL_Log(&quot;Shaders supported, press SPACE to cycle them.\n&quot;);
</pre>
</div>
<div style="font-family:monospace" class="parity1">
<pre><a class="linenr" href="#l460" id="l460">   460</a>     } else {
</pre>
</div>
<div style="font-family:monospace" class="parity0">
<pre><a class="linenr" href="#l461" id="l461">   461</a>         SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, &quot;Shaders not supported!\n&quot;);
</pre>
</div>
<div style="font-family:monospace" class="parity1">
<pre><a class="linenr" href="#l462" id="l462">   462</a>     }
</pre>
</div>
<div style="font-family:monospace" class="parity0">
<pre><a class="linenr" href="#l463" id="l463">   463</a>     done = 0;
</pre>
</div>
<div style="font-family:monospace" class="parity1">
<pre><a class="linenr" href="#l464" id="l464">   464</a>     while ( ! done ) {
</pre>
</div>
<div style="font-family:monospace" class="parity0">
<pre><a class="linenr" href="#l465" id="l465">   465</a>         DrawGLScene(window, texture, texcoords);
</pre>
</div>
<div style="font-family:monospace" class="parity1">
<pre><a class="linenr" href="#l466" id="l466">   466</a> 
</pre>
</div>
<div style="font-family:monospace" class="parity0">
<pre><a class="linenr" href="#l467" id="l467">   467</a>         /* This could go in a separate function */
</pre>
</div>
<div style="font-family:monospace" class="parity1">
<pre><a class="linenr" href="#l468" id="l468">   468</a>         { SDL_Event event;
</pre>
</div>
<div style="font-family:monospace" class="parity0">
<pre><a class="linenr" href="#l469" id="l469">   469</a>             while ( SDL_PollEvent(&amp;event) ) {
</pre>
</div>
<div style="font-family:monospace" class="parity1">
<pre><a class="linenr" href="#l470" id="l470">   470</a>                 if ( event.type == SDL_QUIT ) {
</pre>
</div>
<div style="font-family:monospace" class="parity0">
<pre><a class="linenr" href="#l471" id="l471">   471</a>                     done = 1;
</pre>
</div>
<div style="font-family:monospace" class="parity1">
<pre><a class="linenr" href="#l472" id="l472">   472</a>                 }
</pre>
</div>
<div style="font-family:monospace" class="parity0">
<pre><a class="linenr" href="#l473" id="l473">   473</a>                 if ( event.type == SDL_KEYDOWN ) {
</pre>
</div>
<div style="font-family:monospace" class="parity1">
<pre><a class="linenr" href="#l474" id="l474">   474</a>                     if ( event.key.keysym.sym == SDLK_SPACE ) {
</pre>
</div>
<div style="font-family:monospace" class="parity0">
<pre><a class="linenr" href="#l475" id="l475">   475</a>                         current_shader = (current_shader + 1) % NUM_SHADERS;
</pre>
</div>
<div style="font-family:monospace" class="parity1">
<pre><a class="linenr" href="#l476" id="l476">   476</a>                     }
</pre>
</div>
<div style="font-family:monospace" class="parity0">
<pre><a class="linenr" href="#l477" id="l477">   477</a>                     if ( event.key.keysym.sym == SDLK_ESCAPE ) {
</pre>
</div>
<div style="font-family:monospace" class="parity1">
<pre><a class="linenr" href="#l478" id="l478">   478</a>                         done = 1;
</pre>
</div>
<div style="font-family:monospace" class="parity0">
<pre><a class="linenr" href="#l479" id="l479">   479</a>                     }
</pre>
</div>
<div style="font-family:monospace" class="parity1">
<pre><a class="linenr" href="#l480" id="l480">   480</a>                 }
</pre>
</div>
<div style="font-family:monospace" class="parity0">
<pre><a class="linenr" href="#l481" id="l481">   481</a>             }
</pre>
</div>
<div style="font-family:monospace" class="parity1">
<pre><a class="linenr" href="#l482" id="l482">   482</a>         }
</pre>
</div>
<div style="font-family:monospace" class="parity0">
<pre><a class="linenr" href="#l483" id="l483">   483</a>     }
</pre>
</div>
<div style="font-family:monospace" class="parity1">
<pre><a class="linenr" href="#l484" id="l484">   484</a>     QuitShaders();
</pre>
</div>
<div style="font-family:monospace" class="parity0">
<pre><a class="linenr" href="#l485" id="l485">   485</a>     SDL_Quit();
</pre>
</div>
<div style="font-family:monospace" class="parity1">
<pre><a class="linenr" href="#l486" id="l486">   486</a>     return 1;
</pre>
</div>
<div style="font-family:monospace" class="parity0">
<pre><a class="linenr" href="#l487" id="l487">   487</a> }
</pre>
</div>
<div style="font-family:monospace" class="parity1">
<pre><a class="linenr" href="#l488" id="l488">   488</a> 
</pre>
</div>
<div style="font-family:monospace" class="parity0">
<pre><a class="linenr" href="#l489" id="l489">   489</a> #else /* HAVE_OPENGL */
</pre>
</div>
<div style="font-family:monospace" class="parity1">
<pre><a class="linenr" href="#l490" id="l490">   490</a> 
</pre>
</div>
<div style="font-family:monospace" class="parity0">
<pre><a class="linenr" href="#l491" id="l491">   491</a> int
</pre>
</div>
<div style="font-family:monospace" class="parity1">
<pre><a class="linenr" href="#l492" id="l492">   492</a> main(int argc, char *argv[])
</pre>
</div>
<div style="font-family:monospace" class="parity0">
<pre><a class="linenr" href="#l493" id="l493">   493</a> {
</pre>
</div>
<div style="font-family:monospace" class="parity1">
<pre><a class="linenr" href="#l494" id="l494">   494</a>     SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, &quot;No OpenGL support on this system\n&quot;);
</pre>
</div>
<div style="font-family:monospace" class="parity0">
<pre><a class="linenr" href="#l495" id="l495">   495</a>     return 1;
</pre>
</div>
<div style="font-family:monospace" class="parity1">
<pre><a class="linenr" href="#l496" id="l496">   496</a> }
</pre>
</div>
<div style="font-family:monospace" class="parity0">
<pre><a class="linenr" href="#l497" id="l497">   497</a> 
</pre>
</div>
<div style="font-family:monospace" class="parity1">
<pre><a class="linenr" href="#l498" id="l498">   498</a> #endif /* HAVE_OPENGL */
</pre>
</div>
<div style="font-family:monospace" class="parity0">
<pre><a class="linenr" href="#l499" id="l499">   499</a> 
</pre>
</div>
<div style="font-family:monospace" class="parity1">
<pre><a class="linenr" href="#l500" id="l500">   500</a> /* vi: set ts=4 sw=4 expandtab: */
</pre>
</div>
</div>

<script type="text/javascript">process_dates()</script>
<div class="page_footer">
<div class="page_footer_text">SDL</div>
<div class="rss_logo">
<a href="/SDL/rss-log">RSS</a>
<a href="/SDL/atom-log">Atom</a>
</div>
<br />

</div>
</body>
</html>

