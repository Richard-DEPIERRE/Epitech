# -*- coding: utf-8 -*-
from app import *
from app.models import *
from flask import *

class API():
    def api_tasks(self):
        tasks = Model().tasks_model()
        return (tasks)
        
    def api_task(self, id):
        tasks = Model().task_model(id)
        return (tasks)
        
    def api_register(self, request, form):
        if request.method == 'POST' and form.validate():
            username = form.username.data
            password = sha256_crypt.encrypt(str(form.password.data))
            Model().register_model(username, password)
            flash('You have now register', 'success')
            redirect(url_for('route_login'))

    def api_login(self, request):
        if request.method == 'POST':
            username = request.form['username']
            password_candidate = request.form['password']
            data = Model().login_model(username)
            if data > 0:
                password = data["password"]
                if sha256_crypt.verify(password_candidate, password):
                    session['logged_in'] = True
                    session['username'] = username
                    flash("You are logged in", 'success')
                    return redirect(url_for("route_dashboard"))
                else:
                    error = "invalid login"
                    return render_template('login.html', error=error)
            else:
                error = "username not found"
                return render_template('login.html', error=error)

    def api_dashboard(self):
        tasks = Model().dashboard_model()
        return (tasks)
        
    def api_add_task(self, request, form):
        if request.method == 'POST' and form.validate():
            title = form.title.data
            Model().add_task_model(title)
            flash('Task Created', 'success')
            return redirect(url_for('route_dashboard'))
        
    def api_edit_task(self, request, form, id):
        if request.method == 'POST' and form.validate():
            title = request.form['title']
            Model().edit_task_model_post(title, id)
            flash('Task Edited', 'success')
            return redirect(url_for('route_dashboard'))
        
    def api_delete_task(self, id):
        Model().delete_task_model(id)