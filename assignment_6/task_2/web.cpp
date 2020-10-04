#include <boost/asio.hpp>
#include <iostream>

using namespace std;
using namespace boost::asio::ip;

class EchoServer {
private:
    class Connection {
    public:
        tcp::socket socket;
        Connection(boost::asio::io_service &io_service) : socket(io_service) {}
    };

    boost::asio::io_service io_service;

    tcp::endpoint endpoint;
    tcp::acceptor acceptor;
     // SCFMXQ

    void handle_request(shared_ptr<Connection> connection) {
        auto read_buffer = make_shared<boost::asio::streambuf>();
        // Read from client until newline ("\r\n")
        async_read_until(connection->socket, *read_buffer, "\r\n",
                         [this, connection, read_buffer](const boost::system::error_code &ec, size_t) {
                             // If not error:
                             if (!ec) {
                                 // Retrieve message from client as string:
                                 istream read_stream(read_buffer.get());
                                 std::string message;
                                 getline(read_stream, message);
                                 message.pop_back(); // Remove "\r" at the end of message

                                 cout << "Message recieved from client: " << message << endl;

                                 // Craft HTML responses
                                 std::string error_response = "HTTP/1.1 404 Not found\n";
                                 std::string response = error_response;

                                 if (message == "GET /en_side HTTP/1.1") {
                                     response.clear();
                                     response = "HTTP/1.1 200 OK\n"
                                               "Content-Type: text/html\n"
                                               "Connection: Closed\r\n\r\n"
                                               "<!DOCTYPE html>"
                                               "<html>"
                                               "<body>"
                                               "<h1>Dette er en side</h1>"
                                               "</body>"
                                               "</html>";
                                     cout << "Message sent to client:\n" << response << endl;
                                 }

                                 if (message == "GET / HTTP/1.1") {
                                     response.clear();
                                     response = "HTTP/1.1 200 OK\n"
                                               "Content-Type: text/html\n"
                                               "Connection: Closed\r\n\r\n"
                                               "<!DOCTYPE html>"
                                               "<html>"
                                               "<body>"
                                               "<h1>Dette er hovedsiden</h1>"
                                               "</body>"
                                               "</html>";
                                     cout << "Message sent to client:\n" << response << endl;
                                 }

                                 auto write_buffer = make_shared<boost::asio::streambuf>();
                                 ostream write_stream(write_buffer.get());

                                 // Add message to be written to client:
                                 write_stream << response << "\r\n";


                                 // Write to client
                                 async_write(connection->socket, *write_buffer,
                                             [this, connection, write_buffer](const boost::system::error_code &ec, size_t) {
                                                 // If not error:
                                                 if (!ec)
                                                     handle_request(connection);
                                             });
                                 return;
                             }
                         });
    }

    void accept() {
        // The (client) connection is added to the lambda parameter and handle_request
        // in order to keep the object alive for as long as it is needed.
        auto connection = make_shared<Connection>(io_service);

        // Accepts a new (client) connection. On connection, immediately start accepting a new connection
        acceptor.async_accept(connection->socket, [this, connection](const boost::system::error_code &ec) {
            accept();
            // If not error:
            if (!ec) {
                handle_request(connection);
            }
        });
    }

public:
    EchoServer() : endpoint(tcp::v4(), 8080), acceptor(io_service, endpoint) {}

    void start() {
        accept();

        io_service.run();
    }
};

int main() {
    EchoServer echo_server;

    cout << "Starting server" << endl;

    echo_server.start();
}
