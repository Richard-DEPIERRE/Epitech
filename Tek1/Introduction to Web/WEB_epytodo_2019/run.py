#!/usr/bin/env python3
from app import app
from app import views

if __name__ == '__main__':
    app.secret_key = 'secret123'
    app.run(debug=True)