# -*- coding: utf-8 -*-
from app import *

# Check if user logged in
def is_logged_in(f):
    @wraps(f)
    def wrap(*args, **kwargs):
        if 'logged_in' in session:
            return f(*args, **kwargs)
        else:
            flash('Unauthorized, Please login', 'danger')
            return redirect(url_for('route_login'))
    return wrap

@app.route('/', methods=['GET'])
def route_index():
    return Controller().index()

@app.route('/user/task')
@is_logged_in
def route_tasks():
    return Controller().tasks()

@app.route('/user/tasks/<string:id>/', methods=['GET'])
def route_task(id):
    return Controller().task(id)

# Register
@app.route('/register', methods=['GET', 'POST'])
def route_register():
    return Controller().register(request)

# Login
@app.route('/signin', methods=['GET', 'POST'])
def route_login():
    return Controller().login(request)

# logout
@app.route('/signout', methods=['GET'])
@is_logged_in
def route_logout():
    return Controller().logout()

# Dashboard
@app.route('/user', methods=['GET'])
@is_logged_in
def route_dashboard():
    return Controller().dashboard()

# Add task
@app.route('/user/task/add', methods=['GET', 'POST'])
@is_logged_in
def route_add_task():
    return Controller().add_task(request)

# Edit task
@app.route('/user/task/edit/<string:id>', methods=['GET', 'POST'])
@is_logged_in
def route_edit_task(id):
    return Controller().edit_task(request, id)

# Delete task
@app.route('/user/task/del/<string:id>', methods=['POST'])
@is_logged_in
def route_delete_task(id):
    return Controller().delete_task(id)