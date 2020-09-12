#include <gtkmm.h>

class Window : public Gtk::Window {
public:
    Gtk::VBox vbox;
    Gtk::Entry entry_first;
    Gtk::Entry entry_last;
    Gtk::Button button;
    Gtk::Label label;
    Gtk::Label label_first;
    Gtk::Label label_last;

    Window() {
        button.set_label("Click here");

        vbox.pack_start(label_first);  //Add the widget label to vbox
        vbox.pack_start(entry_first);  //Add the widget entry to vbox
        vbox.pack_start(label_last);  //Add the widget label to vbox
        vbox.pack_start(entry_last);  //Add the widget entry to vbox
        vbox.pack_start(button); //Add the widget button to vbox
        vbox.pack_start(label);  //Add the widget label to vbox

        add(vbox);  //Add vbox to window
        show_all(); //Show all widgets

        label_first.set_text("First name");
        label_last.set_text("Last name");

        button.set_sensitive(false);

        entry_first.signal_changed().connect([this]() {
            button.set_sensitive((entry_first.get_text_length() != 0 && entry_last.get_text_length() != 0));
            label.set_text("Entry now contains: " + entry_first.get_text() + entry_last.get_text());
        });

        entry_last.signal_changed().connect([this]() {
            button.set_sensitive((entry_first.get_text_length() != 0 && entry_last.get_text_length() != 0));
            label.set_text("Entry now contains: " + entry_first.get_text() + " " + entry_last.get_text());
        });

        entry_first.signal_activate().connect([this]() {
            label.set_text("First name entry activated");
        });

        entry_last.signal_activate().connect([this]() {
            label.set_text("Last name entry activated");
        });


        button.signal_clicked().connect([this]() {
            label.set_text("Button clicked");
        });
    }
};

int main() {
    Gtk::Main gtk_main;
    Window window;
    gtk_main.run(window);
}
