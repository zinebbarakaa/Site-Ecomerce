<?php 
$serverName = "FATIMACHHAIB199\SQLEXPRESS"; 
$uid = "";   
$pwd = "";  
$databaseName = "ACHATS_ENLIGNE"; 

$connectionInfo = array( "Database"=>$databaseName,"UID"=>$uid,                            
                         "PWD"=>$pwd)                            
                         ; 

/* Connect using SQL Server Authentication. */  
$conn = sqlsrv_connect( $serverName, $connectionInfo);  

if(!$conn)
	{echo "connexion failed";}


?>