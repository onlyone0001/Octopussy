<%
my %arg = @_;
my $lang = $Session->{AAT_LANGUAGE};
my @devices = ARRAY($arg{devices});
my @services = ARRAY($arg{services});
my @used_services = Octopussy::Service::List_Used();
%>
<AAT:Form action="$arg{url}">
<AAT:Box align="C" title="_MSG_DYNAMIC_ALERT_CREATION" icon="buttons/bt_alert">
<AAT:BoxRow>
	<AAT:BoxCol></AAT:BoxCol>
	<AAT:BoxCol><AAT:Label value="_ALERT_NAME" style="B"/> (only [-_a-zA-Z0-9] chars)</AAT:BoxCol>
	<AAT:BoxCol><AAT:Entry name="alert" size="60" /></AAT:BoxCol>
</AAT:BoxRow>
<AAT:BoxRow>
	<AAT:BoxCol></AAT:BoxCol>
  <AAT:BoxCol><AAT:Label value="_ALERT_DESCRIPTION" style="B"/></AAT:BoxCol>
  <AAT:BoxCol><AAT:Entry name="description" size="60" /></AAT:BoxCol>
</AAT:BoxRow>
<AAT:BoxRow>
	<AAT:BoxCol></AAT:BoxCol>
  <AAT:BoxCol><AAT:Label value="_ALERT_LEVEL" style="B"/></AAT:BoxCol>
  <AAT:BoxCol>
	<AAT:Inc file="octo_selector_alert_level" name="level" /></AAT:BoxCol>
</AAT:BoxRow>
<AAT:BoxRow><AAT:BoxCol cspan="3"><hr></AAT:BoxCol></AAT:BoxRow>
<AAT:BoxRow>
	<AAT:BoxCol><AAT:Button name="device" /></AAT:BoxCol>
  <AAT:BoxCol><AAT:Label value="_DEVICES" style="B"/></AAT:BoxCol>
	<AAT:BoxCol>
	<AAT:Inc file="octo_selector_device_and_devicegroup_dynamic" 
	multiple="1" size="10" selected=\@devices /></AAT:BoxCol>
</AAT:BoxRow>
<AAT:BoxRow>
	<AAT:BoxCol><AAT:Button name="service" /></AAT:BoxCol>
  <AAT:BoxCol><AAT:Label value="_SERVICES" style="B"/></AAT:BoxCol>
  <AAT:BoxCol><AAT:Inc file="octo_selector_service_dynamic"
  multiple="1" size="10" selected=\@services 
	restricted_services=\@used_services /></AAT:BoxCol>
</AAT:BoxRow>
<AAT:BoxRow>
  <AAT:BoxCol></AAT:BoxCol>
  <AAT:BoxCol><AAT:Label value="_LOG_LEVEL" style="B"/></AAT:BoxCol>
  <AAT:BoxCol><AAT:Inc file="octo_selector_loglevel" any="1" /></AAT:BoxCol>
</AAT:BoxRow>
<AAT:BoxRow>
	<AAT:BoxCol></AAT:BoxCol>
  <AAT:BoxCol><AAT:Label value="_TAXONOMY" style="B"/></AAT:BoxCol>
  <AAT:BoxCol><AAT:Inc file="octo_selector_taxonomy" any="1" /></AAT:BoxCol>
</AAT:BoxRow>
<AAT:BoxRow>
	<AAT:BoxCol><AAT:Button name="period" /></AAT:BoxCol>
  <AAT:BoxCol><AAT:Label value="_TIMEPERIOD" style="B"/></AAT:BoxCol>
  <AAT:BoxCol><AAT:Inc file="octo_selector_timeperiod" /></AAT:BoxCol>
</AAT:BoxRow>
<AAT:BoxRow>
	<AAT:BoxCol><AAT:Button name="msg_ok" /></AAT:BoxCol>
  <AAT:BoxCol><AAT:Label value="_REGEXP_INC" style="B" /></AAT:BoxCol>
	<AAT:BoxCol>
	<AAT:Entry name="regexp_include" value="$regexp_include" size="40" />
  </AAT:BoxCol>
</AAT:BoxRow>
<AAT:BoxRow>
	<AAT:BoxCol><AAT:Button name="msg_critical" /></AAT:BoxCol>
  <AAT:BoxCol><AAT:Label value="_REGEXP_EXC" style="B" /></AAT:BoxCol>
  <AAT:BoxCol>
  <AAT:Entry name="regexp_exclude" value="$regexp_exclude" size="40" />
  </AAT:BoxCol>
</AAT:BoxRow>
<AAT:BoxRow><AAT:BoxCol cspan="3"><hr></AAT:BoxCol></AAT:BoxRow>
<AAT:BoxRow>
	<AAT:BoxCol></AAT:BoxCol>
  <AAT:BoxCol><AAT:Label value="_REPETITION_N" style="B"/></AAT:BoxCol>
  <AAT:BoxCol>
	<AAT:Selector_Number name="thresold_time" min="1" max="100" /></AAT:BoxCol>
</AAT:BoxRow>
<AAT:BoxRow>
	<AAT:BoxCol></AAT:BoxCol>
  <AAT:BoxCol><AAT:Label value="_DURATION_D" style="B"/></AAT:BoxCol>
  <AAT:BoxCol>
	<AAT:Selector_Number name="thresold_duration" min="0" max="600" step="5"/>
	</AAT:BoxCol>
</AAT:BoxRow>
<AAT:BoxRow>
    <AAT:BoxCol></AAT:BoxCol>
  <AAT:BoxCol><AAT:Label value="_MINIMUM_DELAY_BETWEEN_2_ALERTS" style="B" /></AAT:BoxCol>
  <AAT:BoxCol><AAT:Entry name="minimum_emit_delay" value="$a_minimum_emit_delay" size="6" /></AAT:BoxCol>
</AAT:BoxRow>
<AAT:BoxRow>
	<AAT:BoxCol></AAT:BoxCol>
	<AAT:BoxCol cspan="2">
	<AAT:Label value="_MSG_ALERT_RAISED_ONLY" color="blue" /></AAT:BoxCol>
</AAT:BoxRow>
<AAT:BoxRow><AAT:BoxCol cspan="3"><hr></AAT:BoxCol></AAT:BoxRow>
<AAT:BoxRow>
	<AAT:BoxCol></AAT:BoxCol>
	<AAT:BoxCol><AAT:Label value="_ACTION" style="B"/></AAT:BoxCol>
	<AAT:BoxCol>
	<AAT:Inc file="octo_selector_action_mailing" multiple="1" size="2" /></AAT:BoxCol>
</AAT:BoxRow>
<AAT:BoxRow>
	<AAT:BoxCol><AAT:Button name="contact" /></AAT:BoxCol>
  <AAT:BoxCol><AAT:Label value="_CONTACTS" style="B"/></AAT:BoxCol>
  <AAT:BoxCol>
	<AAT:Inc file="octo_selector_contact" multiple="1" size="3" /></AAT:BoxCol>
</AAT:BoxRow>
<AAT:BoxRow>
	<AAT:BoxCol></AAT:BoxCol>
  <AAT:BoxCol>
	<AAT:Label value="_SUBJECT" tooltip="_TOOLTIP_ALERT_MSG" style="B"/>
	</AAT:BoxCol>
  <AAT:BoxCol><AAT:Entry name="subject" size="60" /></AAT:BoxCol>
</AAT:BoxRow>
<AAT:BoxRow>
	<AAT:BoxCol></AAT:BoxCol>
  <AAT:BoxCol>
	<AAT:Label value="_BODY" tooltip="_TOOLTIP_ALERT_MSG" style="B"/></AAT:BoxCol>
  <AAT:BoxCol><AAT:TextArea name="body" cols="60" rows="5" /></AAT:BoxCol>
</AAT:BoxRow>
<AAT:BoxRow><AAT:BoxCol cspan="3"><hr></AAT:BoxCol></AAT:BoxRow>
<AAT:BoxRow>
  <AAT:BoxCol></AAT:BoxCol>
  <AAT:BoxCol><AAT:Label value="_ACTION" style="B"/></AAT:BoxCol>
  <AAT:BoxCol>
  <AAT:Inc file="octo_selector_action_program" multiple="1" size="2" /></AAT:BoxCol>
</AAT:BoxRow>
<AAT:BoxRow>
  <AAT:BoxCol></AAT:BoxCol>
  <AAT:BoxCol>
  <AAT:Label value="_HOST" tooltip="_TOOLTIP_ALERT_MSG" style="B"/>
  </AAT:BoxCol>
  <AAT:BoxCol><AAT:Entry name="action_host" size="30" /></AAT:BoxCol>
</AAT:BoxRow>
<AAT:BoxRow>
  <AAT:BoxCol></AAT:BoxCol>
  <AAT:BoxCol>
  <AAT:Label value="_SERVICE" tooltip="_TOOLTIP_ALERT_MSG" style="B"/>
  </AAT:BoxCol>
  <AAT:BoxCol><AAT:Entry name="action_service" size="30" /></AAT:BoxCol>
</AAT:BoxRow>
<AAT:BoxRow>
  <AAT:BoxCol></AAT:BoxCol>
  <AAT:BoxCol>
  <AAT:Label value="_BODY" tooltip="_TOOLTIP_ALERT_MSG" style="B"/></AAT:BoxCol>
  <AAT:BoxCol><AAT:TextArea name="action_body" cols="60" rows="5" /></AAT:BoxCol>
</AAT:BoxRow>
<AAT:BoxRow><AAT:BoxCol cspan="3"><hr></AAT:BoxCol></AAT:BoxRow>
<AAT:BoxRow>
	<AAT:BoxCol cspan="3" align="C">
	<AAT:Form_Submit value="_NEW_DYNAMIC_ALERT" /></AAT:BoxCol>
</AAT:BoxRow>
</AAT:Box>
</AAT:Form>
