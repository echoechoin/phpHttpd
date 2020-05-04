<!DOCTYPE html>
<html lang="en" class="no-js">
  <head>
    <meta charset="UTF-8" />
    <meta http-equiv="X-UA-Compatible" content="IE=edge"> 
    <title>Welcome.</title>
    <meta name="viewport" content="width=device-width, initial-scale=1, maximum-scale=1" />
    <meta name="description" content="BreezyCV - Resume / CV / vCard Template" />
    <meta name="keywords" content="vcard, resposnive, retina, resume, jquery, css3, bootstrap, Material CV, portfolio" />
    <meta name="author" content="lmpixels" />
    <link rel="shortcut icon" href="favicon.ico">


    <link rel="stylesheet" href="css/reset.css" type="text/css">
    <link rel="stylesheet" href="css/bootstrap-grid.min.css" type="text/css">
    <link rel="stylesheet" href="css/animations.css" type="text/css">
    <link rel="stylesheet" href="css/perfect-scrollbar.css" type="text/css">
    <link rel="stylesheet" href="css/owl.carousel.css" type="text/css">
    <link rel="stylesheet" href="css/magnific-popup.css" type="text/css">
    <link rel="stylesheet" href="css/main.css" type="text/css">

    <script src="js/modernizr.custom.js"></script>
  </head>

  <body>
    <!-- Animated Background -->
    <div class="lm-animated-bg" style="background-image: url(img/main_bg.png);"></div>
    <!-- /Animated Background -->

    <!-- Loading animation -->
    <div class="preloader">
      <div class="preloader-animation">
        <div class="preloader-spinner">
        </div>
      </div>
    </div>
    <!-- /Loading animation -->

    <div class="page">
      <div class="page-content">

          <header id="site_header" class="header mobile-menu-hide">
            <div class="header-content">
              <div class="header-photo">
                <img src="img/phpserver.jpg" alt="Alex Smith">
              </div>
              <div class="header-titles">
                <h4>PhpHttpd 使用高效率的Libevent事件通知库连接Web服务器和php-fpm。并将返回的数据呈现到前端。</h4>
              </div>
            </div>

            <ul class="main-menu">
              <li class="active">
                <a href="#home" class="nav-anim">
                  <span class="menu-icon lnr lnr-home"></span>
                  <span class="link-text">Home</span>
                </a>
              </li>
              <li>
                <a href="#about-me" class="nav-anim">
                  <span class="menu-icon lnr lnr-user"></span>
                  <span class="link-text">About Project</span>
                </a>
              </li>
              <li>
                <a href="#contact" class="nav-anim">
                  <span class="menu-icon lnr lnr-envelope"></span>
                  <span class="link-text">Contact</span>
                </a>
              </li>
            </ul>


            <div class="header-buttons">
              <a href="https://github.com/echoechoin/phpHttpd" target="_blank" class="btn btn-primary">@Github</a>
            </div>
          </header>

          <!-- Mobile Navigation -->
          <div class="menu-toggle">
            <span></span>
            <span></span>
            <span></span>
          </div>
          <!-- End Mobile Navigation -->

          <!-- Arrows Nav -->
          <div class="lmpixels-arrows-nav">
            <div class="lmpixels-arrow-right"><i class="lnr lnr-chevron-right"></i></div>
            <div class="lmpixels-arrow-left"><i class="lnr lnr-chevron-left"></i></div>
          </div>
          <!-- End Arrows Nav -->

          <div class="content-area">
            <div class="animated-sections">
              <!-- Home Subpage -->
              <section data-id="home" class="animated-section start-page">
                <div class="section-content vcentered">

                    <div class="row">
                      <div class="col-sm-12 col-md-12 col-lg-12">
                        <div class="title-block">
                          <h2>PhpHttpd</h2>
                          <div class="owl-carousel text-rotation">                                    
                            <div class="item">
                              <div class="sp-subtitle">a simple web server.</div>
                            </div>
                            
                            <div class="item">
                              <div class="sp-subtitle">using efficient Libevent </div>
                            </div>
                          </div>
                        </div>
                      </div>
                    </div>

                </div>
              </section>
              <!-- End of Home Subpage -->

              <!-- About Me Subpage -->
              <section data-id="about-me" class="animated-section">
                <div class="page-title">
                  <h2>关于 <span>项目</span></h2>
                </div>

                <div class="section-content">
                  <!-- Personal Information -->
                  <div class="row">
                    <div class="col-xs-12 col-sm-12">
                      <p>在做毕业设计的时候，对http协议不太了解，因此混合C语言和C++的写法构建了一个简单的Web服务器。该服务器使用Libevent事件通知库管理connect sockets，将接收的GET或者POST参数传递给php-fpm的本地套接字，再通过读取php-fpm返回的结果将数据呈现给用户。</p>
                    </div>

          
                  </div>
                  <!-- End of Personal Information -->

                  <div class="white-space-50"></div>

                  <!-- test -->
                  <div class="block-title">
                    <h3>参数传递<span>测试</span></h3>
                  </div>
                  <form action="" method="post">
                    <div class="form-group form-group-with-icon">
                      <input id="param1" type="text" name="param1" class="form-control" placeholder="">
                      <label>参数1</label>
                      <div class="form-control-border"></div>
                      <div class="help-block with-errors"></div>
                    </div>
                  
                    <div class="form-group form-group-with-icon">
                      <input id="param2" type="text" name="param2" class="form-control" placeholder="">
                      <label>参数2</label>
                      <div class="form-control-border"></div>
                      <div class="help-block with-errors"></div>
                    </div>
                    <input type="submit" class="button btn-send" value="POST">
                  </form>
                  <?php
                    if(isset($_POST['param1']) || isset($_POST['param2'])){
                      echo "<h4>参数1: ".$_POST['param1']."<h4>";
                      echo "<h4>参数2: ".$_POST['param2']."<h4>";
                    }
                  ?>
                  <div class="white-space-50"></div>
                  <!-- End of Test -->

                  <!-- Services -->
                  <div class="row">
                    <div class="col-xs-12 col-sm-12">
                      <div class="block-title">
                        <h3>PhpHttpd <span>怎么运作的</span></h3>
                      </div>
                    </div>
                  </div>

                  <div class="row">
                    <div class=" col-xs-12 col-sm-12 ">
                      <div class="fw-pricing clearfix row">
                        
                        <div class="fw-package-wrap col-md-6 ">
                          <div class="fw-package">
                            <div class="header-photo">
                              <img src="img/libevent.jpg" alt="Alex Smith">
                            </div>
                            libevent是一个基于事件通知机制的库，支持select、epoll等事件机制，它是一个跨操作系统的库。目前应用该库的有Chromium、Memcached、NTP、tmux等应用。
                          </div>
                        </div>

                        <div class="fw-package-wrap col-md-6 ">
                          <div class="fw-package">
                            <div class="header-photo">
                              <img src="img/phpfpm.jpg" alt="Alex Smith">
                            </div>
                            PHP-FPM(FastCGI Process Manager：FastCGI进程管理器)是一个PHPFastCGI管理器。CGI(公共网关接口)作为一个窗口联通了php和web server。
                          </div>
                        </div>

                      </div>
                    </div>
                  </div>
                  <!-- End of Pricing -->

                  <div class="white-space-50"></div>

                  <!-- Fun Facts -->
                  <div class="row">
                    <div class="col-xs-12 col-sm-12">

                      <div class="block-title">
                        <h3>Git<span>hub</span></h3>
                      </div>
                    </div>
                  </div>

                  <div class="row" >
                    <div class="col-xs-12 col-sm-4" onclick="alert('Thanks~');">
                      <div class="fun-fact gray-default">
                        <i class="lnr lnr-heart" style="color:red;"></i>
                        <h4>Like</h4>

                        <span class="fun-fact-block-text"></span>
                      </div>
                    </div>

                    <div class="col-xs-12 col-sm-4 ">
                    <a href="https://github.com/echoechoin/phpHttpd">  
                      <div class="fun-fact gray-default">
                          <i class="lnr lnr-star" style="color:red"></i>
                          <h4> Star</h4>
                          <span class="fun-fact-block-text"></span>
                        </div>
                      </div>
                    </a>
                  </div>
                  <!-- End of Fun Facts -->

                </div>
              </section>
              <!-- End of About Me Subpage -->

              <!-- Contact Subpage -->
              <section data-id="contact" class="animated-section">
                <div class="page-title">
                  <h2>联系我</h2>
                </div>

                <div class="section-content">

                  <div class="row">
                    <!-- Contact Info -->
                    <div class="col-xs-12 col-sm-4">

                      <div class="lm-info-block gray-default">
                        <i class="lnr lnr-phone-handset"></i>
                        <h4>177-2187-4323</h4>
                        <span class="lm-info-block-value"></span>
                        <span class="lm-info-block-text"></span>
                      </div>

                      <div class="lm-info-block gray-default">
                        <i class="lnr lnr-envelope"></i>
                        <h4>admin@study644.top</h4>
                        <span class="lm-info-block-value"></span>
                        <span class="lm-info-block-text"></span>
                      </div>

                    </div>
                    <!-- End of Contact Info -->

                    <!-- Contact Form -->
                    <div class="col-xs-12 col-sm-8">
                      <div class="block-title">
                        <h3>也可以在这里 <span>留言</span></h3>
                      </div>

                      <form  action="contactme.php" method="post">

                        <div class="messages"></div>

                        <div class="controls two-columns">
                          <div class="fields clearfix">
                            <div class="left-column">
                              <div class="form-group form-group-with-icon">
                                <input id="form_name" type="text" name="name" class="form-control" placeholder="" required="required" data-error="不要留空啦！！！ Σ(っ °Д °;)っ">
                                <label>昵称</label>
                                <div class="form-control-border"></div>
                                <div class="help-block with-errors"></div>
                              </div>

                              <div class="form-group form-group-with-icon">
                                <input id="form_email" type="text" name="contact" class="form-control" placeholder="" required="required" data-error="什么方式都可以≖‿≖✧">
                                <label>联系方式</label>
                                <div class="form-control-border"></div>
                                <div class="help-block with-errors"></div>
                              </div>
                            </div>
                            <div class="right-column">
                              <div class="form-group form-group-with-icon">
                                <textarea id="form_message" name="message" class="form-control" placeholder="" rows="7" required="required" data-error="不给我留言吗？～～((ノ*T_T*)ノ"></textarea>
                                <label>留言</label>
                                <div class="form-control-border"></div>
                                <div class="help-block with-errors"></div>
                              </div>
                            </div>
                          </div>

                          <div class="g-recaptcha" data-sitekey="6LdqmCAUAAAAAMMNEZvn6g4W5e0or2sZmAVpxVqI"></div>
      
                          <input type="submit" class="button btn-send" value="发送">
                        </div>
                      </form>
                    </div>
                    <!-- End of Contact Form -->
                  </div>

                </div>
              </section>
              <!-- End of Contact Subpage -->
            </div>
          </div>

      </div>
    </div>

    <script src="js/jquery-2.1.3.min.js"></script>
    <script src="js/modernizr.custom.js"></script>
    <script src="js/animating.js"></script>

    <script src="js/imagesloaded.pkgd.min.js"></script>

    <script src='js/perfect-scrollbar.min.js'></script>
    <script src='js/jquery.shuffle.min.js'></script>
    <script src='js/masonry.pkgd.min.js'></script>
    <script src='js/owl.carousel.min.js'></script>
    <script src="js/jquery.magnific-popup.min.js"></script>

    <script src="js/jquery.googlemap.js"></script>
    <script src="js/validator.js"></script>
    <script src="js/main.js"></script>
  </body>
</html>
