#include <orni/orni.hpp>

//  note this auth is still basic and unencrypted

std::string regPage =
    ""
    "<!DOCTYPE html>\n"
    "<html>\n"
    "<head>\n"
    "</head>\n"
    "<body>\n"
    "<form method=\"POST\">\n"
    "<input name=\"username\" placeholder=\"username\"/>\n"
    "<br/><br/>\n"
    "<input name=\"password\" type=\"password\" placeholder=\"password\"/>\n"
    "<button type=\"submit\">submit</button>\n"
    "</form>\n"
    "</body>\n"
    "</html>";

int main() {
    orni::HttpServer app;
    app.Get("/", [&](orni::Request& req, orni::Response& res) {
        std::string username = req.Cookies["username"];
        if (username.empty()) {
            res.send("auth required ! head to /register");
        } else {
            res.send("hello " + username + " !");
        }
    });
    app.route("/register",
              [&](orni::Request& req, orni::Response& res) {
                  if (req.Method == "GET") {
                      res.set("Content-Type", "text/html");
                      res.send(regPage);
                  } else if (req.Method == "POST") {
                      res.addCookie("username", req.Form["username"]);
                      res.addCookie("password", req.Form["password"]);
                      res.setStatus(201);
                      res.send("created !");
                  }
              },
              {onri::HttpMethods::Get, orni::HttpMethods::Post});
    app.run();
}
