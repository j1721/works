from django.urls import path
from . import views

urlpatterns = [
    path('hello/', views.hello, name='hello'),   
    path('list/', views.list, name='list'), 
    path('detail/<int:pk>/', views.detail, name='detail'), 
    path('create', views.create, name='create'), 
    path('update/<int:pk>', views.update, name='update'), 
    path('delete/<int:pk>', views.delete, name='delete'),
    path('get_info/', views.get_info, name='get_info'),  
]