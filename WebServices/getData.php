<?php

include_once 'funciones.php'; 
include_once 'Functions.php'; 	
include_once 'ServerSettings.php'; 		
include_once 'InitServerConnection.php'; 

header("Access-Control-Allow-Headers: *");
header("Access-Control-Allow-Origin: *");
header("Access-Control-Allow-Headers: X-Requested-With");
header('Content-Type: application/json');

/*$_POST['command']="setResponse";

$_POST['user']="jorge22344";
$_POST['response']="37";
$_POST['question']="4";
$_POST['columnIndex']="-1";
*/
if (isset($_POST['command'])) {
  if ($_POST['command']=="getQuestions") {
      $user=$_POST['user'];
      
      $query = "INSERT INTO ".$_SESSION['answers']." (user) VALUES (:user)";
	    $parameters = array(':user' => $user);
	    $stmtInsert = ExecuteQuery($query, $parameters);
      $rs = ExecuteQuery("SELECT LAST_INSERT_ID()");

      $rsA=$rs->fetch(PDO::FETCH_ASSOC);
      $id=0;
      foreach ($rsA as &$value) {
        $id= $value;
      }
      
      $query = "SELECT * FROM ".$_SESSION['questions']."  ORDER BY questions.order ASC ";
      $stmt = ExecuteQuery($query);
      $items = $stmt->fetchAll(PDO::FETCH_ASSOC);

      header("HTTP/1.1 200 OK");
      
      $res = array(
      'index' => $id,
      'data' => $items
    );
      
      $myJSON=json_encode($res);
      echo $myJSON;
      }
      
      if ($_POST['command']=="setResponse") {
      $response=$_POST['response'];
      $question=$_POST['question'];
      $columnIndex=$_POST['columnIndex'];
      
       
      
      $query = "UPDATE `answers` SET `a".$question."`=".$response." WHERE `index`=".$columnIndex;
      $stmt = ExecuteQuery($query);

      $query = "SELECT * FROM ".$_SESSION['tokens']." ";
      $stmt = ExecuteQuery($query);
      $items = $stmt->fetchAll(PDO::FETCH_ASSOC);

      header("HTTP/1.1 200 OK");
      
      $myJSON=json_encode($items);
      echo $myJSON;
      }
}else{
  echo "Api:\n\n\n";
  
  echo "getQuestions\n";
  echo "post command=getQuestions\n";
  echo "post user=username\n\n";
  
  echo "setResponse\n";
  echo "post command=setResponse\n";
  echo "post question=questionInt\n";
  echo "post response=responseInt 0 for no 1 for yes\n";
  echo "post columnIndex=columnIndex given in getQuestions service \n";
  echo "returns latest tokens values \n\n";
}

close();
?>