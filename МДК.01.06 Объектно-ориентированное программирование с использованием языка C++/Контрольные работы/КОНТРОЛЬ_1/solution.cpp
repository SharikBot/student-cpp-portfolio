
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// ===== Movie =====
class Movie {
private:
    string title;
    string genre;
    double rating;
    int length;

public:
    Movie(string t, string g, double r, int d) {
        title = t;
        genre = g;
        rating = r;
        length = d;
    }

    string getTitle() { return title; }
    string getGenre() { return genre; }
    double getRating() { return rating; }
    int getDuration() { return length; }

    void setTitle(const string& t) { title = t; }
    void setGenre(const string& g) { genre = g; }
    void setRating(double r) { rating = r; }
    void setDuration(int d) { length = d; }

    void show() {
        cout << "Title: " << title
             << "\nGenre: " << genre
             << "\nRating: " << rating
             << "\nDuration: " << length << " min\n" << endl;
    }
};


// ===== Catalog =====
class Catalog {
private:
    vector<Movie> list;

public:
    void add(string t, string g, double r, int d) {
        list.emplace_back(t, g, r, d);
        cout << "Movie added\n";
    }

    void remove(const string& t) {
        for (int i = 0; i < list.size(); i++) {
            if (list[i].getTitle() == t) {
                list.erase(list.begin() + i);
                cout << "Movie removed\n";
                return;
            }
        }
        cout << "Not found\n";
    }

    void search(const string& t) {
        for (auto& m : list) {
            if (m.getTitle() == t) {
                m.show();
                return;
            }
        }
        cout << "Not found\n";
    }

    void edit(const string& t) {
        for (auto& m : list) {
            if (m.getTitle() == t) {
                cout << "Editing movie:\n";
                m.show();

                string nt, ng;
                double nr;
                int nd;

                cout << "New title: ";
                getline(cin, nt);
                if (!nt.empty()) m.setTitle(nt);

                cout << "New genre: ";
                getline(cin, ng);
                if (!ng.empty()) m.setGenre(ng);

                cout << "New rating: ";
                cin >> nr;
                if (nr > 0) m.setRating(nr);

                cout << "New duration: ";
                cin >> nd;
                if (nd > 0) m.setDuration(nd);

                cin.ignore();
                cout << "Updated\n";
                return;
            }
        }
        cout << "Not found\n";
    }

    void filter(const string& g) {
        bool ok = false;

        string target = g;
        transform(target.begin(), target.end(), target.begin(), ::tolower);

        for (auto& m : list) {
            string mg = m.getGenre();
            transform(mg.begin(), mg.end(), mg.begin(), ::tolower);

            if (mg == target) {
                m.show();
                ok = true;
            }
        }

        if (!ok) cout << "No movies in this genre\n";
    }

    void showAll() {
        if (list.empty()) {
            cout << "Empty catalog\n";
            return;
        }

        cout << "\n--- Movies ---\n";
        for (auto& m : list) {
            m.show();
        }
    }
};


// ===== main =====
int main() {
    setlocale(LC_ALL, "ru");

    Catalog c;
    int choice;

    do {
        cout << "\n1.Show\n2.Add\n3.Search\n4.Remove\n5.Edit\n6.Filter\n0.Exit\n> ";
        cin >> choice;
        cin.ignore();

        if (choice == 1) {
            c.showAll();
        }
        else if (choice == 2) {
            string t, g;
            double r;
            int d;

            cout << "Title: ";
            getline(cin, t);

            cout << "Genre: ";
            getline(cin, g);

            cout << "Rating: ";
            cin >> r;

            cout << "Duration: ";
            cin >> d;

            cin.ignore();
            c.add(t, g, r, d);
        }
        else if (choice == 3) {
            string t;
            cout << "Title: ";
            getline(cin, t);
            c.search(t);
        }
        else if (choice == 4) {
            string t;
            cout << "Title: ";
            getline(cin, t);
            c.remove(t);
        }
        else if (choice == 5) {
            string t;
            cout << "Title: ";
            getline(cin, t);
            c.edit(t);
        }
        else if (choice == 6) {
            string g;
            cout << "Genre: ";
            getline(cin, g);
            c.filter(g);
        }

    } while (choice != 0);

    return 0;
}