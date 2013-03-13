
#include <iostream>

#include "boost/date_time/local_time/local_time.hpp"

#include <cppcms/application.h>
#include <cppcms/applications_pool.h>
#include <cppcms/service.h>
#include <cppcms/http_request.h>
#include <cppcms/http_response.h>

class my_hello_world : public cppcms::application {
public:
  my_hello_world(cppcms::service &srv) :
    cppcms::application(srv) 
  {
  }
  virtual void main(std::string url);
  void get(); // modelled after GAE and others
  void post();
};

void my_hello_world::main(std::string url)
{
  std::cout << boost::posix_time::second_clock::local_time() << std::endl ;
  if (request().request_method()=="GET") {
    get();
    return ;
  }
  if (request().request_method()=="POST") {
    post();
    return;
  }
}

void my_hello_world::get() {
  response().content_type("text/plain");
  response().out() << request().request_method() << "\n"
                   << request().remote_addr() << "\n"
                   << request().remote_host() << "\n" ;
  //"<html>\n<body>\n<h1>Hello World</h1>\n"
  //                 <<   << "foobar\n</body>\n</html>\n";
}

void my_hello_world::post() {
}

int main(int argc,char ** argv)
{
    try {
        cppcms::service srv(argc,argv);
        srv.applications_pool().mount(cppcms::applications_factory<my_hello_world>());
        srv.run();
    }
    catch(std::exception const &e) {
        std::cerr<<e.what()<<std::endl;
    }
}
// vim: tabstop=4 expandtab shiftwidth=4 softtabstop=4
